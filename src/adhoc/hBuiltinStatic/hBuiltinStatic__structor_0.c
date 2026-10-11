#include "types.h"
#include "gt4/hBuiltinStatic.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hValue__structor_0();                            /* extern */

extern char hBuiltinStatic__vtable[];
s32 hBuiltinStatic__structor_0(struct hBuiltinStatic *arg0, s32 arg1, s32 arg2, s32 arg3) {
    hValue__structor_0();
    arg0->unk10 = arg3;
    arg0->unkC = arg2;
    arg0->unk4 = (s32)hBuiltinStatic__vtable;
}
