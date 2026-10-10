#include "gt4/mLoggerControl.h"
typedef int s32;

extern void *mLoggerControl__vtable;
extern "C" void func_00574EE8(void *);
extern "C" void func_00578908(void *);
extern "C" void func_00578AF0(void *);
extern "C" void func_005C1628(void *);
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_005760A8(void *, s32);
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mLoggerControl__structor_1(void *arg0, s32 arg1) {
    ((struct mLoggerControl *)arg0)->unk4 = &mLoggerControl__vtable;
    ((struct mLoggerControl *)arg0)->unk2A0 = (void *)(0x1);
    func_00574EE8((char *)arg0 + 0x48);
    func_00578908(((struct mLoggerControl *)arg0)->unk78);
    func_00578AF0(((struct mLoggerControl *)arg0)->unk78);
    func_005C1628(((struct mLoggerControl *)arg0)->unk2B4);
    func_00574DA8((char *)arg0 + 0x48, 0x2);
    func_00574DA8((char *)arg0 + 0x18, 0x2);
    func_005760A8((char *)arg0 + 0x10, 0x2);
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x310, 0x4, "RefCounter");
    }
}
