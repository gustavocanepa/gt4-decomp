#include "types.h"
#include "gt4/hLocalVariable.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00309360(s32, s32);                    /* extern */
s32 hVariable__structor_0();                            /* extern */

extern char hLocalVariable__vtable[];
void hLocalVariable__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hVariable__structor_0();
    ((struct hLocalVariable *)arg0)->unk4 = (s32)hLocalVariable__vtable;
    func_00309360(arg0 + 0x14, arg2);
}
