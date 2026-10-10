#include "gt4/mOption.h"
typedef int s32;

extern "C" int func_0017FC78(void) throw();

extern "C" void mOption__virtual_09(struct mOption *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0017FC78();
    }
}
