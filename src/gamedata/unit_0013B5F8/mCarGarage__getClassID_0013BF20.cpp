#include "gt4/mCarGarage.h"
typedef int s32;

extern "C" int mCarGarage__GetClassID(void) throw();

extern "C" void mCarGarage__getClassID(struct mCarGarage *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCarGarage__GetClassID();
    }
}
