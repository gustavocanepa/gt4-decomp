/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578168(s32 *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

void func_00578230(s32 *arg0, s32 arg1, s32 arg2) {
    func_00578500(*arg0);
    func_00578168(arg0, arg1, arg2, 0, 0);
}
