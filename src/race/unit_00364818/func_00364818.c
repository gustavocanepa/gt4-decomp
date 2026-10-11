#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0034F3F8(s32, s32, s32);               /* extern */
f32 func_00356EA8(s32);                             /* extern */

struct func_00364818_temp_s0 {
    char pad0[0x1700];
    f32 unk1700;
};

void func_00364818(void **arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = *arg0;
    func_0034F3F8(temp_s0 + 0x734, temp_s0 + 0x1700, arg1);
    ((struct func_00364818_temp_s0 *)temp_s0)->unk1700 = (f32) (((struct func_00364818_temp_s0 *)temp_s0)->unk1700 + func_00356EA8(temp_s0 + 0x834));
}
