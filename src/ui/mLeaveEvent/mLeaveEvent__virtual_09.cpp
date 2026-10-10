#include "gt4/mLeaveEvent.h"
typedef int s32;

extern "C" int func_002ADE78(void) throw();

extern "C" void mLeaveEvent__virtual_09(struct mLeaveEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002ADE78();
    }
}
