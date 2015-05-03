#ifndef __TETRIS__
#define __TETRIS__

#include "../music.h"

struct note* tetris()
{
//1
	struct note *cn_ptr;
	struct note *n_ptr=music_add(NULL, NULL, E5, T4);
	cn_ptr=n_ptr;
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T8);
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, A5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, B4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);     
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);     
//         music_
	cn_ptr=music_add(cn_ptr, n_ptr, 0, T2);

	return n_ptr;
}


#endif
