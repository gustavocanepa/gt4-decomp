#include "gt4/hFunctionValue.h"
typedef int s32;

extern "C" void hValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hFunctionValue__vtable;

extern "C" void hFunctionValue__structor_1(struct hFunctionValue *arg0, s32 arg1) {
    arg0->unk4 = &hFunctionValue__vtable;
    hValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC, 4, "RefCounter");
    }
}
