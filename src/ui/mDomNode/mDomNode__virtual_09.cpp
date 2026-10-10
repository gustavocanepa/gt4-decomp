#include "gt4/mDomNode.h"
typedef int s32;

extern "C" int func_002090C0(void) throw();

extern "C" void mDomNode__virtual_09(struct mDomNode *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002090C0();
    }
}
