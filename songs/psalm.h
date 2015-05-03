#ifndef __PSALM__
#define __PSALM__

#include "../music.h"

struct note* psalm()
{
//1
	struct note *cn_ptr=NULL;
	struct note *n_ptr=NULL;
	cn_ptr=(n_ptr=music_add(cn_ptr, n_ptr, F4, T8+T4));


	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T8);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T16-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T4-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8+T4);


	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8+T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8+T16);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8+T16-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8+T4-T32);
	// Pause
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T8+T4);


	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T8);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T16);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T16-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T4-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8+T4);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);


	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8+T8-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8+T16);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8+T16-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8+T4-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T8+T4);


	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8+T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8+T8);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8+T8-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8+T8);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8+T8-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);


	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8+T4-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8+T8);
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T32);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8+T8-T32);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8+T4);


	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8+T2);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T8+T4);


	cn_ptr=music_add(cn_ptr, n_ptr, F4, T8+T2);




	cn_ptr=music_add(cn_ptr, n_ptr, 0, T8+T2);

	return n_ptr;
}


#endif
