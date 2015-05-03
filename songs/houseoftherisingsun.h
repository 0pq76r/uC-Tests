#ifndef __HOTRS__
#define __HOTRS__

#include "../music.h"

struct note* houseoftherisingsun()
{
//1
	struct note *cn_ptr;
	struct note *n_ptr=music_add(NULL, NULL, D4, T4);
	cn_ptr=n_ptr;
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T1);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, Cis4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, Cis4, T4);     
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T1);
//
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T2);

	return n_ptr;
}


#endif
