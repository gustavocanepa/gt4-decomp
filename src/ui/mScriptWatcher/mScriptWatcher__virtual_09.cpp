#include "gt4/mScriptWatcher.h"
typedef int s32;

extern "C" int func_002CE690(void) throw();

extern "C" void mScriptWatcher__virtual_09(struct mScriptWatcher *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002CE690();
    }
}
