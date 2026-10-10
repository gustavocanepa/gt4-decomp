#include "types.h"
#include "gt4/mOption.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hObject__structor_2(void *, s32);             /* extern */
s32 func_004362E0(s32, s32);                /* extern */
s32 func_00575DA0(void *);                      /* extern */

extern char mOption__vtable[];
void mOption__structor_2(void *arg0, s32 arg1) {
    ((struct mOption *)arg0)->unk4 = (s32)mOption__vtable;
    func_004362E0(arg0 + 0x18, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        func_00575DA0(arg0);
    }
}
