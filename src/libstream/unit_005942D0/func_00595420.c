/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_00595420.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00595420_arg0 {
    char pad0[0x8];
    s32 unk8;
};
struct func_00595420_arg1 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_00595420(struct func_00595420_arg0 *arg0, struct func_00595420_arg1 *arg1) {
    return arg0->unk8 - arg1->unk8;
}
