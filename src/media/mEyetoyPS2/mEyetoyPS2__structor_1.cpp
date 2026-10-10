#include "gt4/mEyetoyPS2.h"
typedef int s32;

extern void *mEyetoyPS2__vtable;
extern "C" void mEyetoyPS2__virtual_50(void *);
extern "C" void mEyetoy__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mEyetoyPS2__structor_1(struct mEyetoyPS2 *arg0, s32 arg1) {
    arg0->unk4 = &mEyetoyPS2__vtable;
    mEyetoyPS2__virtual_50(arg0);
    mEyetoy__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x20, 0x4, "RefCounter");
    }
}
