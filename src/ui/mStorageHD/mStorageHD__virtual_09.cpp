#include "gt4/mStorageHD.h"
typedef int s32;

extern "C" int func_00242640(void) throw();

extern "C" void mStorageHD__virtual_09(struct mStorageHD *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00242640();
    }
}
