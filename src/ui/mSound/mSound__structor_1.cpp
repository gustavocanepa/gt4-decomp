#include "gt4/mSound.h"
typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_0023F890(void *);
extern "C" void func_002C2878(void *, s32);
extern "C" void hObject__structor_2(void *, s32);

extern void *mSound__vtable;

extern "C" void mSound__structor_1(void *arg0, s32 arg1) {
    ((struct mSound *)arg0)->unk4 = &mSound__vtable;
    func_0023F890(arg0);
    func_002C2878((char *)arg0 + 0x14, 2);
    func_002C2878((char *)arg0 + 0x10, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
