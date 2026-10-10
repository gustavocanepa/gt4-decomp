#include "gt4/mUpdateContextPS2.h"
typedef int s32;

extern "C" int func_002135A8(void) throw();

extern "C" void mUpdateContextPS2__virtual_09(struct mUpdateContextPS2 *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002135A8();
    }
}
