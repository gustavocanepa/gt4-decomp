#include "gt4/mUnit.h"
typedef int s32;

extern "C" int func_001AED80(void) throw();

extern "C" void mUnit__virtual_09(struct mUnit *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001AED80();
    }
}
