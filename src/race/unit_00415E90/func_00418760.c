#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00416D10();                            /* extern */
s32 func_00419810(s32, s32);                    /* extern */

s32 func_00418760(s32 arg0, s32 arg1) {
    func_00416D10();
    func_00419810(arg0 + 0x360, arg1 + 0x360);
    return arg0;
}
