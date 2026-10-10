#include "gt4/hBuiltinFunction.h"
typedef int s32;

extern void *hBuiltinFunction__vtable;
extern "C" void *hFunctionValue__structor_0(void *);

extern "C" void *hBuiltinFunction__structor_0(struct hBuiltinFunction *arg0, s32 arg1, s32 arg2) {
    void *r0 = hFunctionValue__structor_0(arg0);
    arg0->unk4 = &hBuiltinFunction__vtable;
    arg0->unkC = (void *)(arg2);
    return r0;
}
