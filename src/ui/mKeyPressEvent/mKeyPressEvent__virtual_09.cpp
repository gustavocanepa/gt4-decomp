#include "gt4/mKeyPressEvent.h"
typedef int s32;

extern "C" int func_002AA748(void) throw();

extern "C" void mKeyPressEvent__virtual_09(struct mKeyPressEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002AA748();
    }
}
