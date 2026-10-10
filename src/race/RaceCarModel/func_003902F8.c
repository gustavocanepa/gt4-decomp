#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00450C48(s32);                         /* extern */
s32 func_00454410(s32);                         /* extern */

void func_003902F8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_00454410(arg1);
        func_00450C48(arg0 + 0x18);
    }
}
