#include "gt4/mLoggerControl.h"
typedef int s32;

extern "C" int func_0011EA58(void) throw();

extern "C" void mLoggerControl__virtual_09(struct mLoggerControl *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0011EA58();
    }
}
