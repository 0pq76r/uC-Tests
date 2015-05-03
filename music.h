#ifndef __MUSIC_H__
#define __MUSIC_H__

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define T64 (750)
#define T32 (1500)
#define T16 (3000)
#define T8  (6000)
#define T4 (12000)
#define T2 (24000)
#define T1 (48000)

#define C4		262
#define Cis4 	277
#define D4 		294
#define Dis4 	311
#define E4 		330
#define F4 		349
#define Fis4 	370
#define G4 		392
#define Gis4 	415
#define A4 		440
#define Ais4 	466
#define B4 		494

#define C5		523
#define Cis5 	554
#define D5 		587
#define Dis5 	622
#define E5 		659
#define F5 		698
#define Fis5 	740
#define G5 		784
#define Gis5 	831
#define A5 		880
#define Ais5 	932
#define B5 		987

struct note
{
	uint16_t freq;
	uint32_t duration;
	struct note *next;	
};

extern inline struct note* music_add(struct note* prev, struct note* next, uint16_t freq, uint32_t dur);
extern void play_62_5_kHz();
extern void initMusic();
extern void music_stop();
extern void music_start();
extern void music_next();

#endif

