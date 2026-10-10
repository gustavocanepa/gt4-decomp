#include "gt4/mMBox.h"
typedef int s32;

extern "C" int func_002B82B0(void) throw();

extern "C" void mMBox__virtual_09(struct mMBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002B82B0();
    }
}
