#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005220F8();                                /* extern */

s32 func_00521638(s32 arg0, s32 *arg1) {
    *arg1 = 0;
    if (func_005220F8() == 0) {
        return 2;
    }
    *arg1 = arg0 + 8;
    return 0;
}
