#include "gt4/mCarData.h"
typedef int s32;

extern "C" int func_0012D648(void) throw();

extern "C" void mCarData__virtual_09(struct mCarData *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0012D648();
    }
}
