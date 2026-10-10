#include "gt4/mUsedCar.h"
typedef int s32;

extern "C" int mUsedCar__GetClassID(void) throw();

extern "C" void mUsedCar__getClassID(struct mUsedCar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mUsedCar__GetClassID();
    }
}
