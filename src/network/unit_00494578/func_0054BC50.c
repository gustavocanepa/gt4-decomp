#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0054AC90(s32, s32, s32, s32, s32);         /* extern */
s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */

extern char D_0064C3E4[];
s32 func_0054BC50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s1;

    func_00576788(*(s32 *)(s32)D_0064C3E4 + 0x34);
    temp_s1 = func_0054AC90(arg0, arg1, arg2, arg3, arg4);
    func_005767C0(*(s32 *)(s32)D_0064C3E4 + 0x34);
    return temp_s1;
}
