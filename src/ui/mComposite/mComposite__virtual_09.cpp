#include "gt4/mComposite.h"
typedef int s32;

extern "C" int func_00204ED8(void) throw();

extern "C" void mComposite__virtual_09(struct mComposite *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00204ED8();
    }
}
