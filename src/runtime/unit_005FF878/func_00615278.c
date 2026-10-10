/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00615278_arg0 {
    char pad0[0x1A];
    u8 unk1A;
};

void func_00615278(struct func_00615278_arg0 *arg0, s32 arg1) {
    arg0->unk1A = (u8) (arg0->unk1A | arg1);
}
