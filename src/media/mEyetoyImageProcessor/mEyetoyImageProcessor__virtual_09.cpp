#include "gt4/mEyetoyImageProcessor.h"
typedef int s32;

extern "C" int func_001B9970(void) throw();

extern "C" void mEyetoyImageProcessor__virtual_09(struct mEyetoyImageProcessor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001B9970();
    }
}
