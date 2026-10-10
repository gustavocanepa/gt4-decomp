#include "gt4/mDomNode.h"
typedef int s32;

extern "C" int mDomNode__GetClassID(void) throw();

extern "C" void mDomNode__getClassID(struct mDomNode *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mDomNode__GetClassID();
    }
}
