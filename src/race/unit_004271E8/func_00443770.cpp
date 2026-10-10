#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004437A8(s32);                         /* extern */
s32 func_00444020(s32, s32);                    /* extern */
s32 func_004440A0();                                /* extern */

void func_00443770(s32 arg0) {
    func_00444020(arg0, func_004440A0());
    func_004437A8(arg0);
}
