#include "gt4/mEyetoy.h"
typedef int s32;

extern "C" int func_001B6908(void) throw();

extern "C" void mEyetoy__virtual_09(struct mEyetoy *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001B6908();
    }
}
