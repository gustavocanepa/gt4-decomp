#include "gt4/mWatcher.h"
typedef int s32;

extern "C" int func_00254260(void) throw();

extern "C" void mWatcher__virtual_09(struct mWatcher *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00254260();
    }
}
