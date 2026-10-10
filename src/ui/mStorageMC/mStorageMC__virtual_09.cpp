#include "gt4/mStorageMC.h"
typedef int s32;

extern "C" int func_002766D8(void) throw();

extern "C" void mStorageMC__virtual_09(struct mStorageMC *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002766D8();
    }
}
