#include "gt4/mWindowEvent.h"
typedef int s32;

extern "C" int func_0026B9A8(void) throw();

extern "C" void mWindowEvent__virtual_09(struct mWindowEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0026B9A8();
    }
}
