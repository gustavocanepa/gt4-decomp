#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00430018(s32);                             /* extern */
s32 func_00437428(s32);                             /* extern */
s32 func_0043A388(s32);                             /* extern */
s32 func_0043B050(s32);                             /* extern */

void func_0043AA00(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;

    temp_s0 = func_0043A388(0x10);
    temp_s0_2 = temp_s0 + func_0043B050(arg0 + 0x348);
    temp_s0_3 = temp_s0_2 + func_00437428(arg0 + 0x38CB0);
    func_0043A388(temp_s0_3 + func_00430018(arg0 + 0x3A368));
}
