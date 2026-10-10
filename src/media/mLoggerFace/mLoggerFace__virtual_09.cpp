#include "gt4/mLoggerFace.h"
typedef int s32;

extern "C" int func_001BBB30(void) throw();

extern "C" void mLoggerFace__virtual_09(struct mLoggerFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001BBB30();
    }
}
