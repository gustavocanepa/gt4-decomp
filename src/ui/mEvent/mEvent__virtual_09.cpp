#include "gt4/mEvent.h"
typedef int s32;

extern "C" int func_0028E310(void) throw();

extern "C" void mEvent__virtual_09(struct mEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0028E310();
    }
}
