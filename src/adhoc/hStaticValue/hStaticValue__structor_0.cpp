#include "gt4/hStaticValue.h"
typedef int s32;

extern "C" s32 func_00309360(void *arg0, s32 arg1);
extern "C" void *hValue__structor_0(void *arg0);
extern char hStaticValue__vtable[];

extern "C" s32 hStaticValue__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hValue__structor_0(arg0);
    ((struct hStaticValue *)arg0)->unk4 = hStaticValue__vtable;
    return func_00309360((char *)arg0 + 0xC, arg2);
}
