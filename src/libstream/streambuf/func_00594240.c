/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::set_column.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00594240_arg0 {
    char pad0[0x48];
    s16 unk48;
};

s32 func_00594240(struct func_00594240_arg0 *arg0, s32 arg1) {
    arg0->unk48 = (s16) (arg1 + 1);
    return 0;
}
