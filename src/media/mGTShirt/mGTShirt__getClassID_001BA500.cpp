#include "gt4/mGTShirt.h"
typedef int s32;

extern "C" int mGTShirt__GetClassID(void) throw();

extern "C" void mGTShirt__getClassID(struct mGTShirt *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mGTShirt__GetClassID();
    }
}
