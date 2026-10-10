#include "gt4/mImage.h"
typedef int s32;

extern "C" void mData__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mImage__vtable;

extern "C" void mImage__structor_1(struct mImage *arg0, s32 arg1) {
    arg0->unk4 = &mImage__vtable;
    mData__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 8, 4, "RefCounter");
    }
}
