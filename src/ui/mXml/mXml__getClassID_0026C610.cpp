#include "gt4/mXml.h"
typedef int s32;

extern "C" int mXml__GetClassID(void) throw();

extern "C" void mXml__getClassID(struct mXml *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mXml__GetClassID();
    }
}
