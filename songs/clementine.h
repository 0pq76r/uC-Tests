#ifndef __CLEMENTINE__
#define __CLEMENTINE__

#include "../music.h"

struct note* clementine()
{
//1
	struct note *cn_ptr=NULL;
	struct note *n_ptr=NULL;
	cn_ptr=(n_ptr=music_add(cn_ptr, n_ptr, G4, T8));
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, Fis4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T16);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
//
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T2);

	return n_ptr;
}


#endif
