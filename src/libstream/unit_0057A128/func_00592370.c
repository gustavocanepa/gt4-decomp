/* libio (GNU iostream library, gcc 2000-10-03 snapshot): ostream::operator<<.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00593020(s32);                         /* extern */
s32 func_00593370(void **);                     /* extern */
s32 _IO_putc(s8, s32);                         /* extern */

struct func_00592370_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x12];
    u8 unk1A;
};

void **func_00592370(void **arg0, s8 arg1) {
    s32 temp_v0;
    s32 var_a0;
    struct func_00592370_temp_v1 *temp_v1;

    temp_v1 = *arg0;
    var_a0 = 0;
    if (temp_v1->unk1A == 0) {
        temp_v0 = temp_v1->unk4;
        if (temp_v0 != 0) {
            func_00593020(temp_v0);
        }
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        if (_IO_putc(arg1, M2C_FIELD(*arg0, s32 *, 0)) == -1) {
            temp_v1 = *arg0;
            temp_v1->unk1A = (u8) (temp_v1->unk1A | 4);
        }
        if (M2C_FIELD(*arg0, s64 *, 0x10) & 0x6000) {
            func_00593370(arg0);
        }
    }
    return arg0;
}
