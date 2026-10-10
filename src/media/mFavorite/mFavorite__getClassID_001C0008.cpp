#include "gt4/mFavorite.h"
typedef int s32;

extern "C" int mFavorite__GetClassID(void) throw();

extern "C" void mFavorite__getClassID(struct mFavorite *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFavorite__GetClassID();
    }
}
