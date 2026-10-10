#include "gt4/mCourseRecord.h"
typedef int s32;

extern "C" int func_0015C860(void) throw();

extern "C" void mCourseRecord__virtual_09(struct mCourseRecord *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0015C860();
    }
}
