#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00522220();                            /* extern */
s32 func_005A4724(s32, s32, s32);       /* extern */

extern char D_00863BC8[];
void func_00521600(s32 arg0) {
    func_00522220();
    func_005A4724(arg0, (s32)D_00863BC8, 0x38);
}
