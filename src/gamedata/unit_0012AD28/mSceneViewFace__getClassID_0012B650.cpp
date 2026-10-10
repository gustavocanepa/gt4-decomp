#include "gt4/mSceneViewFace.h"
typedef int s32;

extern "C" int mSceneViewFace__GetClassID(void) throw();

extern "C" void mSceneViewFace__getClassID(struct mSceneViewFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mSceneViewFace__GetClassID();
    }
}
