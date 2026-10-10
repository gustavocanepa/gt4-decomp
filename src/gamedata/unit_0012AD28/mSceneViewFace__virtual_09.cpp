#include "gt4/mSceneViewFace.h"
typedef int s32;

extern "C" int func_0012B640(void) throw();

extern "C" void mSceneViewFace__virtual_09(struct mSceneViewFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0012B640();
    }
}
