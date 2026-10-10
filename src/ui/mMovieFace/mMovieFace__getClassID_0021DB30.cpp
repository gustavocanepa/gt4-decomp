#include "gt4/mMovieFace.h"
typedef int s32;

extern "C" int mMovieFace__GetClassID(void) throw();

extern "C" void mMovieFace__getClassID(struct mMovieFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mMovieFace__GetClassID();
    }
}
