#include "gt4/mManager.h"
typedef int s32;

extern "C" int func_002113A0(void) throw();

extern "C" void mManager__virtual_09(struct mManager *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002113A0();
    }
}
