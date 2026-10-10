#include "gt4/mScriptEvent.h"
typedef int s32;

extern "C" int mScriptEvent__GetClassID(void) throw();

extern "C" void mScriptEvent__getClassID(struct mScriptEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mScriptEvent__GetClassID();
    }
}
