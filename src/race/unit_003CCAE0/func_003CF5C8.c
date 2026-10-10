#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0035BEB0(s32);                             /* extern */
s32 Pitmen__is_tireman(s32);                             /* extern */
s32 func_003CC960(s32);                             /* extern */
s32 func_003CC970(s32);                             /* extern */
s32 func_003CF6F0(s32);                             /* extern */
s32 func_003CF730(s32, s32, s32);                   /* extern */
s32 func_003CF780(s32, s32);                        /* extern */
s32 func_003D29B0(s32, s32, s32);               /* extern */
s32 func_003D2A50(s32, s32);                        /* extern */

s32 func_003CF5C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;

    if (Pitmen__is_tireman(arg1) != 0) {
        return func_003CF6F0(arg3);
    }
    if (func_003CC960(arg1) != 0) {
        temp_s0 = func_0035BEB0(arg2);
        return func_003CF730(arg3, temp_s0, func_003D2A50(arg0, arg4));
    }
    if (func_003CC970(arg1) != 0) {
        return func_003CF780(arg3, func_003D29B0(arg0, arg4, -1));
    }
    return 0x8FFFFFFF;
}
