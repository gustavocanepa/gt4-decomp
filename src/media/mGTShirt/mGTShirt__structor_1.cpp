#include "gt4/mGTShirt.h"
typedef int s32;

extern "C" void mEyetoyImageProcessor__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mGTShirt__vtable;

extern "C" void mGTShirt__structor_1(struct mGTShirt *arg0, s32 arg1) {
    arg0->unk4 = &mGTShirt__vtable;
    mEyetoyImageProcessor__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
