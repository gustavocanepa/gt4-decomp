#include "gt4/hNil.h"
typedef int s32;

extern "C" int hNil__GetClassID(void) throw();

extern "C" void hNil__getClassID(struct hNil *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hNil__GetClassID();
    }
}
