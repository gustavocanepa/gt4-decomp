#include "gt4/mScrollArrow.h"
typedef int s32;

extern "C" int func_002D0710(void) throw();

extern "C" void mScrollArrow__virtual_09(struct mScrollArrow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002D0710();
    }
}
