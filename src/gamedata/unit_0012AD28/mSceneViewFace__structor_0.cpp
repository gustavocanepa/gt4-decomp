#include "gt4/mSceneViewFace.h"
typedef int s32;

extern void *mSceneViewFace__vtable;
extern "C" void *mWidget__structor_0(void *);

extern "C" void *mSceneViewFace__structor_0(struct mSceneViewFace *arg0) {
    void *r0 = mWidget__structor_0(arg0);
    arg0->unkA0 = 0x0;
    arg0->unk4 = &mSceneViewFace__vtable;
    arg0->unkA4 = 0x0;
    arg0->unkA8 = 0x0;
    arg0->unkB0 = 0x0;
    arg0->unkB4 = 0x0;
    arg0->unkB8 = 0x0;
    return r0;
}
