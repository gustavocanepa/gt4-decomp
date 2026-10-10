#include "gt4/mLicenseRecordUnit.h"
typedef int s32;

extern "C" int mLicenseRecordUnit__GetClassID(void) throw();

extern "C" void mLicenseRecordUnit__getClassID(struct mLicenseRecordUnit *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mLicenseRecordUnit__GetClassID();
    }
}
