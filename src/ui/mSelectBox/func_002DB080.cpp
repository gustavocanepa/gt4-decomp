#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002319C0(s32);                             /* extern */
s32 func_002DAB50(s32, s32);                    /* extern */
s32 func_002DB300(s32, s32);                    /* extern */
s32 func_0057CE40(s32, s32);                    /* extern */

void func_002DB080(s32 arg0, s32 arg1, s32 arg2) {
    func_0057CE40(arg0 + 0xBC, arg2);
    func_002DB300(arg0, func_002319C0(arg1));
    func_002DAB50(arg0, arg1);
}
