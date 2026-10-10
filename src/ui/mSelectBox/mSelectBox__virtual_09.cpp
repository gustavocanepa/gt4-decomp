#include "gt4/mSelectBox.h"
typedef int s32;

extern "C" int func_002D8C58(void) throw();

extern "C" void mSelectBox__virtual_09(struct mSelectBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002D8C58();
    }
}
