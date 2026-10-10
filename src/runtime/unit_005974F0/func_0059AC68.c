/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_file_init.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00594520();                            /* extern */

struct func_0059AC68_arg0 {
    s32 unk0;
    char pad4[0x34];
    s32 unk38;
    char pad3C[0x4];
    s64 unk40;
};

void func_0059AC68(struct func_0059AC68_arg0 *arg0) {
    arg0->unk40 = -1;
    arg0->unk0 = (s32) (arg0->unk0 | 0x240C);
    func_00594520();
    arg0->unk38 = -1;
}
