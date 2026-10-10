#include "gt4/mHttp.h"
typedef int s32;

extern "C" int func_001D7028(void) throw();

extern "C" void mHttp__virtual_09(struct mHttp *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001D7028();
    }
}
