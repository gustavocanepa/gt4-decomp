#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00536590(s8 arg0, u16 *arg1) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg1 != NULL) {
        *arg1 = 0;
        if (arg0 & 0x10) {
            *arg1 = 0x2000;
        }
        if (arg0 & 0x40) {
            *arg1 |= 0x4000;
        }
        if (arg0 & 0x80) {
            *arg1 |= 0x1000;
        }
        var_v0 = 0;
    }
    return var_v0;
}
