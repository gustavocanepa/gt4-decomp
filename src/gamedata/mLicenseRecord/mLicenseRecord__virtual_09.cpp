#include "gt4/mLicenseRecord.h"
typedef int s32;

extern "C" int func_00172640(void) throw();

extern "C" void mLicenseRecord__virtual_09(struct mLicenseRecord *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00172640();
    }
}
