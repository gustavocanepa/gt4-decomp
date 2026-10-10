#include "gt4/mNetConfPS2.h"
typedef int s32;

extern "C" int func_00274890(void) throw();

extern "C" void mNetConfPS2__virtual_09(struct mNetConfPS2 *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00274890();
    }
}
