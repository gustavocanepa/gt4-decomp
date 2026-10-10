#include "gt4/mLocale.h"
typedef int s32;

extern "C" int func_002B60A0(void) throw();

extern "C" void mLocale__virtual_09(struct mLocale *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002B60A0();
    }
}
