#include "gt4/mFBox.h"
typedef int s32;

extern "C" int func_0028F690(void) throw();

extern "C" void mFBox__virtual_09(struct mFBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0028F690();
    }
}
