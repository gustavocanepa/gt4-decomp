#include "gt4/mProgress.h"
typedef int s32;

extern "C" int func_00228628(void) throw();

extern "C" void mProgress__virtual_09(struct mProgress *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00228628();
    }
}
