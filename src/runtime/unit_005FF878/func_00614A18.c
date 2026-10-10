/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_005941E8(s32);                             /* extern */

struct func_00614A18_temp_a0 {
    s32 unk0;
    char pad4[0x16];
    u8 unk1A;
};

void **func_00614A18(void **arg0) {
    struct func_00614A18_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    if (temp_a0->unk1A == 0) {
        if (func_005941E8(temp_a0->unk0) == -1) {
            M2C_FIELD(*arg0, u8 *, 0x1A) = 4U;
        }
    }
    return arg0;
}
