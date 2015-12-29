//Wernli Florian

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BAUD (9600)
#define UBR_VAL ((F_CPU/16/BAUD)-1)

#define BUFLEN 512

enum ADCState{Idle, Triggered, Sending};

static volatile int do_send;
static volatile uint16_t buf[BUFLEN];

void initADC()
{
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADIE)
		|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}


ISR(ADC_vect){
	uint16_t adc=ADC;
	static int i;

#ifdef DEBUG
	DDRA=0xff;
	PORTA^=0xff;
#endif

	static enum ADCState state=Idle;
	switch(state)
	{
		case Idle:
#ifdef DEBUG
	DDRA=0xff;
	PORTA=0xf0;
#endif

			if(adc<(1024/2))
			{
				i=0;
				buf[i++]=adc;
				state=Triggered;
			}
		break;
		case Triggered:
#ifdef DEBUG
	DDRA=0xff;
	PORTA=0x00;
#endif
			if(i>=BUFLEN)
			{
				do_send=1;
				state=Sending;
				break;
			}
			buf[i++]=adc;
		break;		
		case Sending:
#ifdef DEBUG
	DDRA=0xff;
	PORTA=do_send;
#endif
			if((!do_send)&&(adc>(1024/2)))
			{
				state=Idle;
			}
		break;
		default:
			state=Idle;
		break;
	}
}

void inti_send_buf()
{
		UBRR0L=UBR_VAL&0xFF;
		UBRR0H=(UBR_VAL>>8)&0xFF;
		UCSR0B=(1<<RXEN0)|(1<<TXEN0);
		UCSR0C=(3<<UCSZ00);
}

int serial_putchar(char ch, FILE *unused)
{
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0=ch;
	return 0;
}

float voltage(uint16_t adc)
{
	return ((float)adc)*5.0/1024.0;
}

int main()
{	
	int i;
	static FILE fd_stdout= FDEV_SETUP_STREAM(serial_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &fd_stdout;
	
	initADC();
	inti_send_buf();

	sei();

	while(1){
		if(do_send==0) continue;
		
		#ifdef DEBUG
			DDRC=0xff;
			PORTC^=0xff;
		#endif

		for(i=0;i<BUFLEN-1;i++)
		{
//			printf("%c,",buf[i]);

			int h=(int)(voltage(buf[i]));
			int l=(int)((voltage(buf[i])*100)+0.5);
			if((l-(h*100))>=100)h++;
			l%=100;
			printf("%d.%d",l,h);
			
		}
//		printf("%c\n",buf[i]);

		int h=(int)(voltage(buf[i]));
		int l=(int)((voltage(buf[i])*100)+0.5);
		if((l-(h*100))>=100)h++;
		l%=100;
		printf("%d.%d",l,h);

		do_send=0;
	}
}

