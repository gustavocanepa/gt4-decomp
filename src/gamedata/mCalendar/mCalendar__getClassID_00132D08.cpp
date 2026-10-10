#include "gt4/mCalendar.h"
typedef int s32;

extern "C" int mCalendar__GetClassID(void) throw();

extern "C" void mCalendar__getClassID(struct mCalendar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCalendar__GetClassID();
    }
}
