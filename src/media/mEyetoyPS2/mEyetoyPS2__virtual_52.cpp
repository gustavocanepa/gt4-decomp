#include "gt4/mEyetoyPS2.h"
typedef int s32;

extern void func_001C4D90(s32);

extern "C" void mEyetoyPS2__virtual_52(struct mEyetoyPS2 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk14;
    if (temp_v0 != 0) {
        func_001C4D90(temp_v0);
    }
}
