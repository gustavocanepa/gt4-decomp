#include "gt4/mButtonReleaseEvent.h"
typedef int s32;

extern "C" int func_00281138(void) throw();

extern "C" void mButtonReleaseEvent__virtual_09(struct mButtonReleaseEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00281138();
    }
}
