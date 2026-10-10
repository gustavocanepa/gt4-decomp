#include "gt4/mCourseData.h"
typedef int s32;

extern "C" int mCourseData__GetClassID(void) throw();

extern "C" void mCourseData__getClassID(struct mCourseData *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCourseData__GetClassID();
    }
}
