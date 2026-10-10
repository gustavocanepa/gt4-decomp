#include "gt4/mDatabase.h"
typedef int s32;

extern "C" int mDatabase__GetClassID(void) throw();

extern "C" void mDatabase__getClassID(struct mDatabase *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mDatabase__GetClassID();
    }
}
