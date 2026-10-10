/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00555228();                            /* extern */
s32 func_00555268(s32);                         /* extern */
s32 func_00555D10(s32, s32, s32, s32, s32);     /* extern */
s32 func_00556210(s32, s32);                        /* extern */

void func_00555C90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00555228();
    if (func_00556210(arg0, arg1) == 0) {
        func_00555D10(arg0, arg1, arg2, arg3, arg3 ^ 1);
    }
    func_00555268(arg0);
}
