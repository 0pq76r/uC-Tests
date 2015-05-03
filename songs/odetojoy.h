#ifndef __ODETOJOY__
#define __ODETOJOY__

#include "../music.h"

struct note* odetojoy()
{
//1
	struct note *cn_ptr;
	struct note *n_ptr=music_add(NULL, NULL, A4, T4);
	cn_ptr=n_ptr;
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
///
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C4, T4);
// END

	return n_ptr;
}


#endif
