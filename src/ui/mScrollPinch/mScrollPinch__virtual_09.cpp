#include "gt4/mScrollPinch.h"
typedef int s32;

extern "C" int func_002D1260(void) throw();

extern "C" void mScrollPinch__virtual_09(struct mScrollPinch *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002D1260();
    }
}
