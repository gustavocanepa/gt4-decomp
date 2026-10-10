#include "gt4/mModelStream.h"
typedef int s32;

extern "C" int mModelStream__GetClassID(void) throw();

extern "C" void mModelStream__getClassID(struct mModelStream *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mModelStream__GetClassID();
    }
}
