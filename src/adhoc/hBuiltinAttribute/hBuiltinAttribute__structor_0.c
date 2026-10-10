#include "types.h"
#include "gt4/hBuiltinAttribute.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hValue__structor_0();                            /* extern */

extern char hBuiltinAttribute__vtable[];
s32 hBuiltinAttribute__structor_0(struct hBuiltinAttribute *arg0, s32 arg1, s32 arg2, s32 arg3) {
    hValue__structor_0();
    arg0->unk10 = arg3;
    arg0->unkC_s32 = arg2;
    arg0->unk4 = (s32)hBuiltinAttribute__vtable;
}
