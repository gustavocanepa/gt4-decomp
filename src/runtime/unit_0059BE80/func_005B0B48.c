#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005AD9D0(s32, s32);                /* extern */
s32 func_005AE850(s32);                     /* extern */

extern char D_006582B0[];
extern char D_00886814[];
void func_005B0B48(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_005AE850(5);
    func_005AD9D0(5, *(s32 *)D_00886814);
    *(s32 *)D_006582B0 = 0;
}
