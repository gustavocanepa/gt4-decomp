#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0054A908(s32, s32, s32, s32);              /* extern */
s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */

extern void *D_0064C3E4;

s32 func_0054AE70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s1;

    func_00576788((char *)D_0064C3E4 + 0x34);
    temp_s1 = func_0054A908(arg0, arg1, arg2, arg3);
    func_005767C0((char *)D_0064C3E4 + 0x34);
    return temp_s1;
}
