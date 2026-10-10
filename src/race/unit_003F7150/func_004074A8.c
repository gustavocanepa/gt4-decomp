#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00407470();                            /* extern */
s32 func_004074F0(s32);                         /* extern */

s32 func_004074A8(s32 *arg0, s32 arg1) {
    func_00407470();
    *arg0 = arg1;
    if (arg1 != 0) {
        func_004074F0(arg1);
    }
}
