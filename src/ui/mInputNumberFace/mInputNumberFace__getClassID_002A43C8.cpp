#include "gt4/mInputNumberFace.h"
typedef int s32;

extern "C" int mInputNumberFace__GetClassID(void) throw();

extern "C" void mInputNumberFace__getClassID(struct mInputNumberFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mInputNumberFace__GetClassID();
    }
}
