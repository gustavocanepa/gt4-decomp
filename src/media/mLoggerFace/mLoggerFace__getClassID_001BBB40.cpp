#include "gt4/mLoggerFace.h"
typedef int s32;

extern "C" int mLoggerFace__GetClassID(void) throw();

extern "C" void mLoggerFace__getClassID(struct mLoggerFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mLoggerFace__GetClassID();
    }
}
