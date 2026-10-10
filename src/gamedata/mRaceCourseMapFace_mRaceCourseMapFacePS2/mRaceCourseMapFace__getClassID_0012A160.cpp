#include "gt4/mRaceCourseMapFacePS2.h"
typedef int s32;

extern "C" int mRaceCourseMapFace__GetClassID(void) throw();

extern "C" void mRaceCourseMapFace__getClassID(struct mRaceCourseMapFacePS2 *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mRaceCourseMapFace__GetClassID();
    }
}
