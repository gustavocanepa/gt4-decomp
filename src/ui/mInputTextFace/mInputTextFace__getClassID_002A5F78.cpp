#include "gt4/mInputTextFace.h"
typedef int s32;

extern "C" int mInputTextFace__GetClassID(void) throw();

extern "C" void mInputTextFace__getClassID(struct mInputTextFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mInputTextFace__GetClassID();
    }
}
