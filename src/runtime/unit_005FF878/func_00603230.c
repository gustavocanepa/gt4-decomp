#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0043A408(s32 *, s32);              /* extern */
s32 SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);             /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char D_00688280[];
void func_00603230(s32 *arg0, s32 arg1) {
    void *temp_s1;
    void *var_s0;

    *arg0 = (s32)D_00688280;
    if (arg0 != (s32 *)-8) {
        var_s0 = arg0 + 0x11C;
        temp_s1 = arg0 + 2;
        if (temp_s1 != var_s0) {
            do {
                var_s0 -= 0x178;
                SPEC_DATABASE__CarEquipments__setVariationOrder(var_s0, 2);
            } while (temp_s1 != var_s0);
        }
    }
    func_0043A408(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
