#include "types.h"
#include "gt4/hArrayElement.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00309360(s32, s32);                    /* extern */
s32 hObject__structor_0();                            /* extern */

extern char hArrayElement__vtable[];
void hArrayElement__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hObject__structor_0();
    ((struct hArrayElement *)arg0)->unk4 = (s32)hArrayElement__vtable;
    func_00309360(arg0 + 0x10, arg1);
    ((struct hArrayElement *)arg0)->unk14 = arg2;
}
