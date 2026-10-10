#include "gt4/mVBox.h"
typedef int s32;

extern "C" int func_002E6D00(void) throw();

extern "C" void mVBox__virtual_09(struct mVBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002E6D00();
    }
}
