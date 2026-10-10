#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00491D00();                                /* extern */
s32 func_00491EA0(s32, s32, s32, s32);          /* extern */

void func_00491D48(s32 arg0, s32 arg1) {
    func_00491EA0(arg0 + 4, arg0 + 8, func_00491D00(), arg1);
}
