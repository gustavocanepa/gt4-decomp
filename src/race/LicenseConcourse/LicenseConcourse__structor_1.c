#include "types.h"
#include "gt4/LicenseConcourse.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 Concourse__structor_1(void *, s32);             /* extern */
s32 func_00575DA0(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char LicenseConcourse__vtable[];
void LicenseConcourse__structor_1(struct LicenseConcourse *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk10 = (s32)LicenseConcourse__vtable;
    temp_v1 = arg0->unk80;
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
    }
    Concourse__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
