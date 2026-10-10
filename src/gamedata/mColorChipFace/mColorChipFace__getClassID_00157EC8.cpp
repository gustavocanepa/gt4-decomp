#include "gt4/mColorChipFace.h"
typedef int s32;

extern "C" int mColorChipFace__GetClassID(void) throw();

extern "C" void mColorChipFace__getClassID(struct mColorChipFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mColorChipFace__GetClassID();
    }
}
