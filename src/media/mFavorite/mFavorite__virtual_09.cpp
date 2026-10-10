#include "gt4/mFavorite.h"
typedef int s32;

extern "C" int func_001BFFF8(void) throw();

extern "C" void mFavorite__virtual_09(struct mFavorite *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001BFFF8();
    }
}
