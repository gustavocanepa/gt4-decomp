/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_006152B8_arg0 {
    char pad0[0x1A];
    u8 unk1A;
};

s32 func_006152B8(struct func_006152B8_arg0 *arg0) {
    return arg0->unk1A & 6;
}
