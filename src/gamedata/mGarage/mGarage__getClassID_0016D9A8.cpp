#include "gt4/mGarage.h"
typedef int s32;

extern "C" int mGarage__GetClassID(void) throw();

extern "C" void mGarage__getClassID(struct mGarage *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mGarage__GetClassID();
    }
}
