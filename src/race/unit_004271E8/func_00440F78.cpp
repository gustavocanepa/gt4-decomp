#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00440FB8(void *, s32, s32, s32);   /* extern */
s32 func_00441248();                                /* extern */
s32 SPEC_DATABASE__CarEquipments__getVariationOrder(s32);                             /* extern */

struct func_00440F78_arg0 {
    char pad0[0x4A0];
    s32 unk4A0;
};

void func_00440F78(void *arg0) {
    func_00440FB8(arg0, 0, SPEC_DATABASE__CarEquipments__getVariationOrder(func_00441248()), ((struct func_00440F78_arg0 *)arg0)->unk4A0);
}
