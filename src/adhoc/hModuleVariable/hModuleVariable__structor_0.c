#include "types.h"
#include "gt4/hModuleVariable.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00309360(s32, s32);                    /* extern */
s32 func_00323B48(void *, s32);                 /* extern */
s32 hVariable__structor_0();                            /* extern */

extern char hModuleVariable__vtable[];
void hModuleVariable__structor_0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    hVariable__structor_0();
    ((struct hModuleVariable *)arg0)->unk4 = (s32)hModuleVariable__vtable;
    func_00309360(arg0 + 0x14, arg2);
    func_00323B48(arg0 + 0x18, arg3);
}
