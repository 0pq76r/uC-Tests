#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

/*
Timer 0,2 8-bit t=256*Prescale/freq
TCCR0A  Timer/Counter Control Register A
------------- NON-PWM
COM0A1 COM0A0 Description
     0      0 Normal port operation, OC0A disconnected
     0      1 Toggle OC0A on Compare Match
     1      0 Clear OC0A on Compare Match
     1      1 Set OC0A on Compare Match

------------- FAST PWM
COM0A1 COM0A0 Description
     0      0 Normal port operation, OC0A disconnected
     0      1 WGM02 = 0: Normal Port Operation, OC0A Disconnected | WGM02 = 1: Toggle OC0A on Compare Match
     1      0 Clear OC0A on Compare Match, set OC0A at BOTTOM (non-inverting mode)
     1      1 Set OC0A on Compare Match, clear OC0A at BOTTOM (inverting mode)

------------- PWM Phasecorreccted
COM0A1 COM0A0 Description
     0      0 Normal port operation, OC0A disconnected
     0      1 WGM02 = 0: Normal Port Operation, OC0A Disconnected | WGM02 = 1: Toggle OC0A on Compare Match
     1      0 Clear OC0A on Compare Match when up-counting. Set OC0A on Compare Match when down-counting
     1      1 Set OC0A on Compare Match when up-counting. Clear OC0A on Compare Match when down-counting	 

TCCR0B  Timer/Counter Control Register B
CS02 CS01 CS00 Description
   0    0    0 No clock source (Timer/Counter stopped)
   0    0    1 clkI/O/(No prescaling)
   0    1    0 clkI/O/8 (From prescaler)
   0    1    1 clkI/O/64 (From prescaler)
   1    0    0 clkI/O/256 (From prescaler)
   1    0    1 clkI/O/1024 (From prescaler)
   1    1    0 External clock source on T0 pin. Clock on falling edge
   1    1    1 External clock source on T0 pin. Clock on rising edge

Mode WGM2B WGM1 WGM0 Operation TOP  Update OCRx  TOV Flag
   0     0    0    0 Normal    0xFF Immediate    0xFF
   1     0    0    1 PWM Corr. 0xFF TOP          0x00
   2     0    1    0 CTC       OCRA Immediate    0xFF
   3     0    1    1 F. PWM    0xFF TOP          0xFF
   5     1    0    1 PWM Corr. OCRA TOP          0xFF
   7     1    1    1 F. PWM    OCRA BOTTOM       TOP

TCNT0  Timer/Counter Register
OCR0A  Output Compare Register A
OCR0B  Output Compare Register B
TIMSK0  Timer/Counter Interrupt Mask Register
  Bit 2  OCIE0B: Timer/Counter Output Compare Match B Interrupt Enable
  Bit 1  OCIE0A: Timer/Counter0 Output Compare Match A Interrupt Enable
  Bit 0  TOIE0: Timer/Counter0 Overflow Interrupt Enable
TIFR0  Timer/Counter 0 Interrupt Flag Register
      Bit 0  TOV0: Timer/Counter0 Overflow Flag
*/
ISR(TIMER0_COMPA_vect){}
void init_T0_CMPA_1ms_timer(){
	TCCR0A |=(1<<WGM01);//CTC-Mode
	TCCR0B |=(1<<CS00)|(1<<CS01);//Prescaler 64
	TIMSK0 |= (1<<TOIE0)|(1<<OCIE0A); //Overfow Interrupt
	OCR0A = 249;//Vergleichswert -> 1ms/
}


/*
STS EICRA  External Interrupt Control Register A INT3:0
STS EICRB  External Interrupt Control Register B INT7:4
OUT EIMSK - External Interrupt Mask Register INT7:0
ISCn1 ISCn0 Description
    0     0 The low level of INTn generates an interrupt request
    0     1 Any edge of INTn generates asynchronously an interrupt request
    1     0 The falling edge of INTn generates asynchronously an interrupt request
    1     1 The rising edge of INTn generates asynchronously an interrupt request
*/


