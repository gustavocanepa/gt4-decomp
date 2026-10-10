#include "gt4/mScriptEvent.h"
typedef int s32;

extern "C" int func_00239EA0(void) throw();

extern "C" void mScriptEvent__virtual_09(struct mScriptEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00239EA0();
    }
}
