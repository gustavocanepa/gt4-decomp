#include "gt4/mSound.h"
typedef int s32;

extern "C" int func_0023DF98(void) throw();

extern "C" void mSound__virtual_09(struct mSound *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0023DF98();
    }
}
