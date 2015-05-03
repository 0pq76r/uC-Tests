#ifndef __HP__
#define __HP__

#include "../music.h"

struct note* hp()
{
//1
	struct note *cn_ptr;
	struct note *n_ptr=music_add(NULL, NULL, D4, T4);
	cn_ptr=n_ptr;
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, Fis4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, Gis4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T1);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, D4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, Dis5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, Dis5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, Dis5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Cis5, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, Cis5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T4);
//
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T1);
// END
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T2);
	
	return n_ptr;
}


#endif
