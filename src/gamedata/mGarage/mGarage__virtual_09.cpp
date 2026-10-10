#include "gt4/mGarage.h"
typedef int s32;

extern "C" int func_0016D998(void) throw();

extern "C" void mGarage__virtual_09(struct mGarage *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0016D998();
    }
}
