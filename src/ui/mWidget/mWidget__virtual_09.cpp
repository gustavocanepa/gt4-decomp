#include "gt4/mWidget.h"
typedef int s32;

extern "C" int func_00255260(void) throw();

extern "C" void mWidget__virtual_09(struct mWidget *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00255260();
    }
}
