#include "gt4/mLicenseRecordUnit.h"
typedef int s32;

extern "C" int func_00171398(void) throw();

extern "C" void mLicenseRecordUnit__virtual_09(struct mLicenseRecordUnit *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00171398();
    }
}
