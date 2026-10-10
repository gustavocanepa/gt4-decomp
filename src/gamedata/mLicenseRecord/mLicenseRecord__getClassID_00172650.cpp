#include "gt4/mLicenseRecord.h"
typedef int s32;

extern "C" int mLicenseRecord__GetClassID(void) throw();

extern "C" void mLicenseRecord__getClassID(struct mLicenseRecord *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mLicenseRecord__GetClassID();
    }
}
