#include "gt4/mMusic.h"
typedef int s32;

extern "C" int func_002C2A20(void) throw();

extern "C" void mMusic__virtual_09(struct mMusic *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002C2A20();
    }
}
