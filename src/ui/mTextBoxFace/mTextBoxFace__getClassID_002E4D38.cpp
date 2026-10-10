#include "gt4/mTextBoxFace.h"
typedef int s32;

extern "C" int mTextBoxFace__GetClassID(void) throw();

extern "C" void mTextBoxFace__getClassID(struct mTextBoxFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mTextBoxFace__GetClassID();
    }
}
