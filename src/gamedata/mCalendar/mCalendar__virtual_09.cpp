#include "gt4/mCalendar.h"
typedef int s32;

extern "C" int func_00132CF8(void) throw();

extern "C" void mCalendar__virtual_09(struct mCalendar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00132CF8();
    }
}
