#include "gt4/mFlashPS2.h"
typedef int s32;

extern "C" void free(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_00272920(void *);
extern "C" void mFlash__structor_1(void *, s32);

extern void *mFlashPS2__vtable;

extern "C" void mFlashPS2__structor_1(struct mFlashPS2 *arg0, s32 arg1) {
    arg0->unk4 = &mFlashPS2__vtable;
    func_00272920(arg0);
    mFlash__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x20, 4, "RefCounter");
    }
}
