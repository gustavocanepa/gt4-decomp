#include "gt4/mLoggerControl.h"
typedef int s32;

extern "C" int mLoggerControl__GetClassID(void) throw();

extern "C" void mLoggerControl__getClassID(struct mLoggerControl *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mLoggerControl__GetClassID();
    }
}
