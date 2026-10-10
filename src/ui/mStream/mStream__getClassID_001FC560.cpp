#include "gt4/mStream.h"
typedef int s32;

extern "C" int mStream__GetClassID(void) throw();

extern "C" void mStream__getClassID(struct mStream *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mStream__GetClassID();
    }
}
