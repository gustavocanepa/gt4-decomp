#include "gt4/mCrossingEvent.h"
typedef int s32;

extern "C" int func_0028B148(void) throw();

extern "C" void mCrossingEvent__virtual_09(struct mCrossingEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0028B148();
    }
}
