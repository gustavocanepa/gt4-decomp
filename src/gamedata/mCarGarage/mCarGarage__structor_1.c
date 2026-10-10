#include "types.h"
#include "gt4/mCarGarage.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00145AD8(void *, s32);                 /* extern */
s32 func_00146628(void *);                      /* extern */
s32 hObject__structor_0();                            /* extern */
s32 func_0043DC20(s32);                         /* extern */
s32 func_00449D58(void *);                      /* extern */
s32 exception__structor_0(s32);                         /* extern */

extern char mCarGarage__vtable[];
void mCarGarage__structor_1(void *arg0, s32 arg1) {
    s32 temp_v0;

    hObject__structor_0();
    ((struct mCarGarage *)arg0)->unk4 = (s32)mCarGarage__vtable;
    ((struct mCarGarage *)arg0)->unk10 = 1;
    temp_v0 = exception__structor_0(0x4C0);
    func_0043DC20(temp_v0);
    ((struct mCarGarage *)arg0)->unk14 = temp_v0;
    func_00449D58(arg0 + 0x18);
    func_00146628(arg0);
    func_00145AD8(arg0, arg1);
}
