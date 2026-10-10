#include "gt4/mHBox.h"
typedef int s32;

extern "C" int func_002A02E8(void) throw();

extern "C" void mHBox__virtual_09(struct mHBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002A02E8();
    }
}
