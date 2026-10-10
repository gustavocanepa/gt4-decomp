#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003678A8();                            /* extern */
s32 func_00367918(s32, s32, s32);               /* extern */
s32 func_00367AF8(s32, s32, s32);               /* extern */

void func_00367C90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003678A8();
    if (arg2 != 0) {
        func_00367AF8(arg0, arg1, arg3);
        func_00367918(arg0, arg1, arg3);
    }
}
