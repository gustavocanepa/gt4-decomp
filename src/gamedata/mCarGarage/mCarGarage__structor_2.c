#include "types.h"
#include "gt4/mCarGarage.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char mCarGarage__vtable[];
void func_00146628(void *);
s32 hObject__structor_0(void *);
void func_00449D58(void *);
void mCarGarage__structor_2(void *arg0, s32 arg1) {
    hObject__structor_0(arg0);
    ((struct mCarGarage *)arg0)->unk4 = (s32)mCarGarage__vtable;
    ((struct mCarGarage *)arg0)->unk14 = arg1;
    ((struct mCarGarage *)arg0)->unk10 = 0;
    func_00449D58((s8 *)arg0 + 0x18);
    func_00146628(arg0);
}
