#include "gt4/mScriptWatcher.h"
typedef int s32;

extern "C" int mScriptWatcher__GetClassID(void) throw();

extern "C" void mScriptWatcher__getClassID(struct mScriptWatcher *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mScriptWatcher__GetClassID();
    }
}
