/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_00594D28.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00594D28_arg0_unk50 {
    char pad0[0x3C];
    s32 (*unk3C)();
};
struct func_00594D28_arg0 {
    char pad0[0x50];
    struct func_00594D28_arg0_unk50 *unk50;
};

void func_00594D28(struct func_00594D28_arg0 *arg0) {
    arg0->unk50->unk3C();
}
