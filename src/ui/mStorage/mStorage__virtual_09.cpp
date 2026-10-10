#include "gt4/mStorage.h"
typedef int s32;

extern "C" int func_00240570(void) throw();

extern "C" void mStorage__virtual_09(struct mStorage *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00240570();
    }
}
