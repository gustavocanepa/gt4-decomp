/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_seekpos.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 _IO_free_backup_area();                            /* extern */

struct func_00596890_arg0_unk50 {
    char pad0[0x4C];
    s32 (*unk4C)(void *, s32, s32);
};
struct func_00596890_arg0 {
    char pad0[0x24];
    s32 unk24;
    char pad28[0x28];
    struct func_00596890_arg0_unk50 *unk50;
};

void _IO_seekpos(struct func_00596890_arg0 *arg0, s32 arg1, s32 arg2) {
    if (arg0->unk24 != 0) {
        _IO_free_backup_area();
    }
    arg0->unk50->unk4C(arg0, arg1, arg2);
}
