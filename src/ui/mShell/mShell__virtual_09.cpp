#include "gt4/mShell.h"
typedef int s32;

extern "C" int func_0023B380(void) throw();

extern "C" void mShell__virtual_09(struct mShell *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0023B380();
    }
}
