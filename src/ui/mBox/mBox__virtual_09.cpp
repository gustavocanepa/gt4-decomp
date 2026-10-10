#include "gt4/mBox.h"
typedef int s32;

extern "C" int func_00200BD0(void) throw();

extern "C" void mBox__virtual_09(struct mBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00200BD0();
    }
}
