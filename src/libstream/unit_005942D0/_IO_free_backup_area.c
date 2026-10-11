/* compiler: ee-gcc2.96-nsa-nosib */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_free_backup_area.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 free(s32);                         /* extern */
s32 _IO_switch_to_main_get_area();                            /* extern */

struct func_005946B0_arg0 {
    s32 unk0;
    char pad4[0x20];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

void _IO_free_backup_area(struct func_005946B0_arg0 *arg0) {
    if (arg0->unk0 & 0x100) {
        _IO_switch_to_main_get_area();
    }
    free(arg0->unk24);
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    arg0->unk28 = 0;
}
