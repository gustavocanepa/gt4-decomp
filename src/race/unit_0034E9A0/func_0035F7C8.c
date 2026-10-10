#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00556CA0();                                /* extern */
s32 func_00557A70(s32, s32, s32);       /* extern */

extern char D_0035F700[];
extern char D_006208B0[];
void func_0035F7C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_00557A70(func_00556CA0(), (s32)D_0035F700, 0);
    *(s32 *)D_006208B0 = 1;
}
