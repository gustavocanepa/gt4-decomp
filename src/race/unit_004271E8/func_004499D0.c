#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00449968(s32, s32, s32, s32);          /* extern */
s32 func_0057F260(s32);                             /* extern */

void func_004499D0(s32 arg0, s32 arg1, s32 arg2) {
    func_00449968(arg0, arg1, arg2, func_0057F260(arg1));
}
