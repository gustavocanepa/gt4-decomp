#include "gt4/mSceneViewFace.h"
typedef int s32;

extern "C" void mWidget__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mSceneViewFace__vtable;

extern "C" void mSceneViewFace__structor_1(struct mSceneViewFace *arg0, s32 arg1) {
    arg0->unk4 = &mSceneViewFace__vtable;
    mWidget__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC0, 4, "RefCounter");
    }
}
