#include "gt4/mGpb.h"
typedef int s32;

extern "C" int mGpb__GetClassID(void) throw();

extern "C" void mGpb__getClassID(struct mGpb *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mGpb__GetClassID();
    }
}
