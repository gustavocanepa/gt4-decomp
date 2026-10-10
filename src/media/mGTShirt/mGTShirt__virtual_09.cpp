#include "gt4/mGTShirt.h"
typedef int s32;

extern "C" int func_001BA4F0(void) throw();

extern "C" void mGTShirt__virtual_09(struct mGTShirt *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001BA4F0();
    }
}
