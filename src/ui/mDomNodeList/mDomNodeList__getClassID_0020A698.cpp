#include "gt4/mDomNodeList.h"
typedef int s32;

extern "C" int mDomNodeList__GetClassID(void) throw();

extern "C" void mDomNodeList__getClassID(struct mDomNodeList *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mDomNodeList__GetClassID();
    }
}
