#include "gt4/mKeytopBox.h"
typedef int s32;

extern "C" int func_002ACF10(void) throw();

extern "C" void mKeytopBox__virtual_09(struct mKeytopBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002ACF10();
    }
}
