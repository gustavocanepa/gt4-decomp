#include "gt4/mPipe.h"
typedef int s32;

extern "C" int func_002272D0(void) throw();

extern "C" void mPipe__virtual_09(struct mPipe *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002272D0();
    }
}
