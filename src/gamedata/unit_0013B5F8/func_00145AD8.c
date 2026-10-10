#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00440E98(s32);                             /* extern */
s32 func_00441298(s32, s32);                /* extern */

struct func_00145AD8_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00145AD8(struct func_00145AD8_arg0 *arg0) {
    s32 temp_s1;

    temp_s1 = func_00440E98(arg0->unk14);
    func_00441298(arg0->unk14, 0);
    return temp_s1;
}
