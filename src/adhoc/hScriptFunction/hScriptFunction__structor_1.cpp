#include "gt4/hScriptFunction.h"
typedef int s32;

extern "C" void func_002F4210(void *arg0, s32 arg1);
extern "C" void hFunctionValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hScriptFunction__vtable;

extern "C" void hScriptFunction__structor_1(void *arg0, s32 arg1) {
    ((struct hScriptFunction *)arg0)->unk4 = &hScriptFunction__vtable;
    func_002F4210((char *)arg0 + 0xC, 2);
    hFunctionValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
