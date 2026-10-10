#include "gt4/mCarFace.h"
typedef int s32;

extern "C" int mCarFace__GetClassID(void) throw();

extern "C" void mCarFace__getClassID(struct mCarFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCarFace__GetClassID();
    }
}
