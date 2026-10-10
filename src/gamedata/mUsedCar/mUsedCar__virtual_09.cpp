#include "gt4/mUsedCar.h"
typedef int s32;

extern "C" int func_001B1ED8(void) throw();

extern "C" void mUsedCar__virtual_09(struct mUsedCar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001B1ED8();
    }
}
