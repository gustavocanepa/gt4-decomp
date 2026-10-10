#include "gt4/mCourseRecordUnit.h"
typedef int s32;

extern "C" int mCourseRecordUnit__GetClassID(void) throw();

extern "C" void mCourseRecordUnit__getClassID(struct mCourseRecordUnit *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCourseRecordUnit__GetClassID();
    }
}
