#include "gt4/hBuiltinMethod.h"
typedef int s32;

extern void *hBuiltinMethod__vtable;
extern "C" void *hMethodValue__structor_0(void *);

extern "C" void *hBuiltinMethod__structor_0(struct hBuiltinMethod *arg0, s32 arg1, s32 arg2) {
    void *r0 = hMethodValue__structor_0(arg0);
    arg0->unk4 = &hBuiltinMethod__vtable;
    arg0->unkC_pvoid = (void *)(arg2);
    return r0;
}
