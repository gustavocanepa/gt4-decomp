#include "gt4/mModelMotion.h"
typedef int s32;

extern "C" void mData__structor_1(void *arg0, s32 arg1);
extern "C" void free(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mModelMotion__vtable;

extern "C" void mModelMotion__structor_1(struct mModelMotion *arg0, s32 arg1) {
    arg0->unk4 = &mModelMotion__vtable;
    if (arg0->unkC != 0) {
        void *p = arg0->unk8;
        arg0->unk8 = 0;
        free(p);
    }
    mData__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x24, 4, "RefCounter");
    }
}
