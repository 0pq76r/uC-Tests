#ifndef __A_QUAI__
#define __A_QUAI__

#include "../music.h"

struct note* a_quai()
{
//1
	struct note *cn_ptr;
	struct note *n_ptr=music_add(NULL, NULL, F5, T2);
	cn_ptr=n_ptr;
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G5, T8);
                                     
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T1);

//5                                     
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);
	                                 
//	cn_ptr=music_add(cn_ptr, n_ptr, 0, T4) ;
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
//9	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G5, T8);
                                     
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, A5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T1);
//13                                 
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T16);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T16);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T16);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T4);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, F5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T2);
//17
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, C5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T1);

	cn_ptr=music_add(cn_ptr, n_ptr, G4, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, A4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, F4, T1);
//21
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, E4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, G4, T8);
	                                 
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, Ais4, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T4);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T8);

	cn_ptr=music_add(cn_ptr, n_ptr, Cis5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, D5, T2);
	cn_ptr=music_add(cn_ptr, n_ptr, E5, T1);

	cn_ptr=music_add(cn_ptr, n_ptr, 0, T2);

	return n_ptr;
}


#endif
