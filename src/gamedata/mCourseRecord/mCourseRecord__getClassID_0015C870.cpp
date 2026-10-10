#include "gt4/mCourseRecord.h"
typedef int s32;

extern "C" int mCourseRecord__GetClassID(void) throw();

extern "C" void mCourseRecord__getClassID(struct mCourseRecord *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCourseRecord__GetClassID();
    }
}
