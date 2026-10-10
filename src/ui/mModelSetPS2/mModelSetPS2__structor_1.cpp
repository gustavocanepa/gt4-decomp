#include "gt4/mModelSetPS2.h"
typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void mModelSet__structor_1(void *, s32);

extern void *mModelSetPS2__vtable;

extern "C" void mModelSetPS2__structor_1(struct mModelSetPS2 *arg0, s32 arg1) {
    arg0->unk4 = &mModelSetPS2__vtable;
    if (arg0->unkC_pvoid != 0) {
        func_00575DA0(arg0->unk8_pvoid);
    }
    mModelSet__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
