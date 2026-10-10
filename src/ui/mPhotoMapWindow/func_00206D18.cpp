#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00206868();                                /* extern */
s32 func_00206878(s32);                             /* extern */
s32 func_00206C28(s32, s32, s32);               /* extern */

void func_00206D18(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_00206868();
    func_00206C28(arg0, temp_s1, func_00206878(arg0));
}
