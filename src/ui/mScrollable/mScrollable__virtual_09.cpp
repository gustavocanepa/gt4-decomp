#include "gt4/mScrollable.h"
typedef int s32;

extern "C" int func_002D4670(void) throw();

extern "C" void mScrollable__virtual_09(struct mScrollable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002D4670();
    }
}
