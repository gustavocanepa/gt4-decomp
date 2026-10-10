#include "gt4/mEyetoyFace.h"
typedef int s32;

extern "C" int func_001B8B30(void) throw();

extern "C" void mEyetoyFace__virtual_09(struct mEyetoyFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001B8B30();
    }
}
