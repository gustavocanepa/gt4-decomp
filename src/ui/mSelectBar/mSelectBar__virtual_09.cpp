#include "gt4/mSelectBar.h"
typedef int s32;

extern "C" int func_002D5628(void) throw();

extern "C" void mSelectBar__virtual_09(struct mSelectBar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002D5628();
    }
}
