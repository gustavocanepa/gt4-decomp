#include "gt4/mCarModel.h"
typedef int s32;

extern "C" int func_001517C8(void) throw();

extern "C" void mCarModel__virtual_09(struct mCarModel *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001517C8();
    }
}
