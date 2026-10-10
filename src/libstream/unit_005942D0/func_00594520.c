/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_link_in.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00657ED8[];
struct func_00594520_arg0 {
    s32 unk0;
    char pad4[0x30];
    void *unk34;
};

void func_00594520(struct func_00594520_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    if (!(temp_v0 & 0x80)) {
        arg0->unk0 = (s32) (temp_v0 | 0x80);
        arg0->unk34 = (void *) *(void **)(s32)D_00657ED8;
        *(void **)(s32)D_00657ED8 = arg0;
    }
}
