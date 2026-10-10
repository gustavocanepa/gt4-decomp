#include "gt4/mWindowContext.h"
typedef int s32;

extern "C" int func_0026A0B0(void) throw();

extern "C" void mWindowContext__virtual_09(struct mWindowContext *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0026A0B0();
    }
}
