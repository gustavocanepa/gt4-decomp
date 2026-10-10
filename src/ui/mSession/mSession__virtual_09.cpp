#include "gt4/mSession.h"
typedef int s32;

extern "C" int func_002DCCD0(void) throw();

extern "C" void mSession__virtual_09(struct mSession *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002DCCD0();
    }
}
