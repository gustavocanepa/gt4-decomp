#include "gt4/hNil.h"
typedef int s32;

extern "C" int func_00300780(void) throw();

extern "C" void hNil__virtual_09(struct hNil *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00300780();
    }
}
