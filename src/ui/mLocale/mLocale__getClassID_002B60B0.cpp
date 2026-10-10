#include "gt4/mLocale.h"
typedef int s32;

extern "C" int mLocale__GetClassID(void) throw();

extern "C" void mLocale__getClassID(struct mLocale *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mLocale__GetClassID();
    }
}
