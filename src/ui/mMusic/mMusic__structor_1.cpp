#include "gt4/mMusic.h"
typedef int s32;

extern "C" void free(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_002C3BA0(void *);
extern "C" void hObject__structor_2(void *, s32);

extern void *mMusic__vtable;

extern "C" void mMusic__structor_1(struct mMusic *arg0, s32 arg1) {
    arg0->unk4 = &mMusic__vtable;
    func_002C3BA0(arg0);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x24, 4, "RefCounter");
    }
}
