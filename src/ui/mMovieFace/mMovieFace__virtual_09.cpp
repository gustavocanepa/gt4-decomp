#include "gt4/mMovieFace.h"
typedef int s32;

extern "C" int func_0021DB20(void) throw();

extern "C" void mMovieFace__virtual_09(struct mMovieFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0021DB20();
    }
}
