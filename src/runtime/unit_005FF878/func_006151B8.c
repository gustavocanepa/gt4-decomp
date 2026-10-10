/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_006151B8_arg0 {
    char pad0[0x18];
    s16 unk18;
};

s16 func_006151B8(struct func_006151B8_arg0 *arg0, s16 arg1) {
    s16 temp_v0;

    temp_v0 = arg0->unk18;
    arg0->unk18 = arg1;
    return temp_v0;
}
