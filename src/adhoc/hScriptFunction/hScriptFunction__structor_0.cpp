#include "gt4/hScriptFunction.h"
typedef int s32;

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *hFunctionValue__structor_0(void *arg0);
extern char hScriptFunction__vtable[];

extern "C" s32 hScriptFunction__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hFunctionValue__structor_0(arg0);
    ((struct hScriptFunction *)arg0)->unk4 = hScriptFunction__vtable;
    return func_002F41F8((char *)arg0 + 0xC, arg2);
}
