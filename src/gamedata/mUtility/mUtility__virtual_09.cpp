#include "gt4/mUtility.h"
typedef int s32;

extern "C" int func_001B0AE0(void) throw();

extern "C" void mUtility__virtual_09(struct mUtility *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001B0AE0();
    }
}
