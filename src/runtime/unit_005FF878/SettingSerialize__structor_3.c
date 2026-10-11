#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 SPEC_DATABASE__CarEquipments__setVariationOrder(s32, s32);                /* extern */
s32 func_0044CF90(s32 *, s32);              /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char SettingSerialize__vtable[];
void SettingSerialize__structor_3(s32 *arg0, s32 arg1) {
    *arg0 = (s32)SettingSerialize__vtable;
    SPEC_DATABASE__CarEquipments__setVariationOrder(arg0 + 2, 2);
    func_0044CF90(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
