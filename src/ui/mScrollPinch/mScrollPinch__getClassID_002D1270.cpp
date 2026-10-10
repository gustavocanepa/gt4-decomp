#include "gt4/mScrollPinch.h"
typedef int s32;

extern "C" int mScrollPinch__GetClassID(void) throw();

extern "C" void mScrollPinch__getClassID(struct mScrollPinch *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mScrollPinch__GetClassID();
    }
}
