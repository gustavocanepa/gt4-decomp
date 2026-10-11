/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578168(s32 *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */
s32 func_005A609C(void *, s32);                 /* extern */

void func_00610728(s32 *arg0, s32 arg1) {
    func_00578500(*arg0);
    func_005A609C(arg0 + 0x10, arg1);
    func_00578168(arg0, 8, 0, 0, 0);
}
