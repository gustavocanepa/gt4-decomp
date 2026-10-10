#include "gt4/mBlob.h"
typedef int s32;

extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mBlob__vtable;

extern "C" void mBlob__structor_1(struct mBlob *arg0, s32 arg1) {
    arg0->unk4_pvoid = &mBlob__vtable;
    if (arg0->unk14_pvoid != 0) {
        void *p = arg0->unk10_pvoid;
        arg0->unk10_pvoid = 0;
        func_00575DA0(p);
    }
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
