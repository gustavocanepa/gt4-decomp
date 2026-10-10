#include "gt4/mImagePS2.h"
typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void mImage__structor_1(void *, s32);

extern void *mImagePS2__vtable;

extern "C" void mImagePS2__structor_1(struct mImagePS2 *arg0, s32 arg1) {
    arg0->unk4 = &mImagePS2__vtable;
    if (arg0->unk20 != 0) {
        void *p = arg0->unk14_pvoid;
        arg0->unk14_pvoid = 0;
        func_00575DA0(p);
    }
    mImage__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x24, 4, "RefCounter");
    }
}
