/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00594100();                            /* extern */

struct func_00615768_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

s32 func_00615768(struct func_00615768_arg0 *arg0) {
    if (arg0->unk1C == 0) {
        func_00594100();
    }
}
