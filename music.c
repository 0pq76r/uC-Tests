#include "music.h"

#define N_SONGS 10

#include "songs/aquai.h"
#include "songs/tetris.h"
#include "songs/hp.h"
#include "songs/odetojoy.h"
#include "songs/houseoftherisingsun.h"
#include "songs/psalm.h"
#include "songs/mybonnie.h"
#include "songs/cancan.h"
#include "songs/twinkletwinkle.h"
#include "songs/clementine.h"

static struct note* n_ptr=NULL;

void play_62_5_kHz()
{
	static uint16_t freq_ct=0;
	static uint32_t dur_ct=0;

	if(n_ptr==NULL) return;
	if(dur_ct>=n_ptr->duration)
	{
		dur_ct=0;
		freq_ct=0;
		n_ptr=n_ptr->next;
		if(n_ptr==NULL) return;
	}
	
	if(freq_ct==(31250/n_ptr->freq))
	{
		PORTA^=0xff;
		freq_ct=0;
	}
			
	freq_ct++;
	dur_ct++;
}


static uint16_t index=0;	
static struct note *playlist[N_SONGS];
static char *playlist_names[] = {
	"A Quai",
	"Tetris",
	"Harry Potter",
	"Ode To Joy",
	"House Of\rThe Rising Sun",
	"Psalm",
	"My Bonnie",
	"Can Can",
	"Twinkle Twinkle\rLittle Star",
	"Clementine",
};

void music_stop()
{
	cli();
	n_ptr=NULL;
	set_char_at(0xA5,1,0);
	cursorTo(2,0);
	sei();
}

void music_start()
{
	cli();
		index%=N_SONGS;
		n_ptr=playlist[index];
		printf("%s\n", playlist_names[index]);
		set_char_at(0x7e,1,0);
		cursorTo(2,0);
	sei();	
}

void music_next()
{
	cli();
		index++;
		index%=N_SONGS;
		n_ptr=playlist[index];
		printf("%s\n", playlist_names[index]);
		set_char_at(0x7e,1,0);
		cursorTo(2,0);
	sei();	
}	

inline struct note* music_add(struct note* prev, struct note* next, uint16_t freq, uint32_t dur)
{
	static size_t s=sizeof(struct note);
	struct note* r;

	r=malloc(s);
	r->duration=dur;
	r->freq=freq;
	
	if(prev != NULL)
		prev->next=r;
		
	r->next=next;

	return r;
}

void initMusic()
{	
	playlist[0]=a_quai();
	playlist[1]=tetris();
	playlist[2]=hp();
	playlist[3]=odetojoy();
	playlist[4]=houseoftherisingsun();
	playlist[5]=psalm();
	playlist[6]=mybonnie();
	playlist[7]=cancan();
	playlist[8]=twinkletwinkle();
	playlist[9]=clementine();
	printf("%s\n", playlist_names[index]);
	set_char_at(0xA5,1,0);
	cursorTo(2,0);
}
