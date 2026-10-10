#include "gt4/mEnterEvent.h"
typedef int s32;

extern "C" int func_0028D888(void) throw();

extern "C" void mEnterEvent__virtual_09(struct mEnterEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0028D888();
    }
}
