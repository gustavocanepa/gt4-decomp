#include "gt4/hThreadGroup.h"
typedef int s32;

extern "C" int func_00322820(void) throw();

extern "C" void hThreadGroup__virtual_09(struct hThreadGroup *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00322820();
    }
}
