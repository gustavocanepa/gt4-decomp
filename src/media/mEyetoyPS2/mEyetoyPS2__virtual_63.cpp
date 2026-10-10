#include "gt4/mEyetoyPS2.h"
typedef int s32;

extern "C" void func_001C4A90(s32 arg0, s32 arg1, s32 arg2);

extern "C" void mEyetoyPS2__virtual_63(struct mEyetoyPS2 *arg0, s32 arg1) {
    s32 temp_v0 = arg0->unk14;
    if (temp_v0 != 0) {
        func_001C4A90(temp_v0 + 0x15C, arg1, 0);
    }
}
