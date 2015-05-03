#ifndef __CANCAN__
#define __CANCAN__

#include "../music.h"

struct note* cancan()
{
//1
	struct note *cn_ptr=NULL;
	struct note *n_ptr=NULL;
	cn_ptr=(n_ptr=music_add(cn_ptr, n_ptr, C4, T1));
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T2-T32);
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C4, T1);
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2-T32);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T2-T32);
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C4, T2);
//
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T2);

	return n_ptr;
}


#endif
