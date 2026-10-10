#include "types.h"
#include "gt4/mMoviePS2.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char mMoviePS2__vtable[];
s32 mMovie__structor_0(void *);
void mMoviePS2__structor_0(struct mMoviePS2 *arg0) {
    mMovie__structor_0(arg0);
    arg0->unk4 = (s32)mMoviePS2__vtable;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
}
