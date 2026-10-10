#include "gt4/mEyetoy.h"
typedef int s32;

extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mEyetoy__vtable;

extern "C" void mEyetoy__structor_1(struct mEyetoy *arg0, s32 arg1) {
    arg0->unk4 = &mEyetoy__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
