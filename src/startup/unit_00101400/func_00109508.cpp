#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectManager__append(s32, s32);                    /* extern */
s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */
s32 func_00579118(s32, s32);                    /* extern */
s32 func_0057CAB8(s32, s32);                        /* extern */

void func_00109508(s32 arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0xC;
    func_00576788(temp_s2);
    if (func_0057CAB8(arg0, arg1) != 0) {
        func_00579118(arg0, arg1);
        GranTurismo4__GameObjectManager__append(arg0, arg1);
    }
    func_005767C0(temp_s2);
}
