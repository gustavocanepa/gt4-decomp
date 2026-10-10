#include "gt4/mSystem.h"
typedef int s32;

extern "C" int func_001ABFD0(void) throw();

extern "C" void mSystem__virtual_09(struct mSystem *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001ABFD0();
    }
}
