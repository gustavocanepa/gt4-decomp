/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_006155B0_arg0 {
    s32 unk0;
    char pad4[0x8];
    s32 unkC;
    char pad10[0x14];
    s32 unk24;
};

s32 func_006155B0(struct func_006155B0_arg0 *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unk24;
    }
    return arg0->unkC;
}
