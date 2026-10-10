#include "gt4/mBlob.h"
typedef int s32;

extern "C" int mBlob__GetClassID(void) throw();

extern "C" void mBlob__getClassID(struct mBlob *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mBlob__GetClassID();
    }
}
