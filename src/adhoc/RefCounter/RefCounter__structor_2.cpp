#include "gt4/RefCounter.h"
typedef int s32;

extern "C" char RefCounter__vtable;
extern "C" char D_0069ECB8[];

extern "C" void func_00326798(struct RefCounter *arg0, s32 arg1, s32 arg2, void *arg3);

extern "C" void RefCounter__structor_2(struct RefCounter *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk4_pvoid = &RefCounter__vtable;
    if (arg1) {
        func_00326798(arg0, 8, 4, D_0069ECB8);
        return;
    }
}
