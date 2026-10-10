#include "types.h"
#include "gt4/mRaceData.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hObject__structor_2(void *, s32);             /* extern */
s32 func_00446FC8(s32, s32);                /* extern */
s32 func_00575DA0(void *);                      /* extern */

extern char mRaceData__vtable[];
void mRaceData__structor_1(void *arg0, s32 arg1) {
    ((struct mRaceData *)arg0)->unk4 = (s32)mRaceData__vtable;
    func_00446FC8(arg0 + 0x10, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        func_00575DA0(arg0);
    }
}
