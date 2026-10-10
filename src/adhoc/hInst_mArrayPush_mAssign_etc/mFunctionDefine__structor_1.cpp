#include "gt4/mFunctionDefine.h"
typedef int s32;

extern "C" void func_002F4210(void *arg0, s32 arg1);
extern "C" void hInst__structor_0(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mFunctionDefine__vtable;

extern "C" void mFunctionDefine__structor_1(void *arg0, s32 arg1) {
    ((struct mFunctionDefine *)arg0)->unk4 = &mFunctionDefine__vtable;
    func_002F4210((char *)arg0 + 0xC, 2);
    hInst__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
