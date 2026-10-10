/* compiler: ee-gcc2.96-nsa-nosib */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_005946B0.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */
s32 func_00594598();                            /* extern */

struct func_005946B0_arg0 {
    s32 unk0;
    char pad4[0x20];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

void func_005946B0(struct func_005946B0_arg0 *arg0) {
    if (arg0->unk0 & 0x100) {
        func_00594598();
    }
    func_00575DA0(arg0->unk24);
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    arg0->unk28 = 0;
}
