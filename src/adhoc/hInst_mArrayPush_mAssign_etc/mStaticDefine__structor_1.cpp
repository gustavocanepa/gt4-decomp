#include "gt4/mStaticDefine.h"
typedef int s32;

extern "C" void func_00323B60(void *arg0, s32 arg1);
extern "C" void hInst__structor_0(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mStaticDefine__vtable;

extern "C" void mStaticDefine__structor_1(void *arg0, s32 arg1) {
    ((struct mStaticDefine *)arg0)->unk4 = &mStaticDefine__vtable;
    func_00323B60((char *)arg0 + 0xC, 2);
    hInst__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
