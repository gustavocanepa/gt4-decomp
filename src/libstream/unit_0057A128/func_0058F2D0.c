/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A48D8(void *, s32, s32);    /* extern */

struct S { char pad[0x10]; void *p; char pad2[0x334 - 0x14]; };
extern struct S D_0087FA80[];
struct func_0058F2D0_p {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s32 unk4;
    char pad8[0x74];
    s32 unk7C;
};

void func_0058F2D0(s32 arg0) {
    s32 i;
    s8 *p;

    p = D_0087FA80[arg0].p;
    for (i = 0; i < 2; i++) {
        ((struct func_0058F2D0_p *)p)->unk0 = 0;
        ((struct func_0058F2D0_p *)p)->unk7C = 0;
        ((struct func_0058F2D0_p *)p)->unk1 = 0;
        ((struct func_0058F2D0_p *)p)->unk3 = 0;
        ((struct func_0058F2D0_p *)p)->unk2 = 0;
        ((struct func_0058F2D0_p *)p)->unk4 = 0;
        func_005A48D8(p + 0x1C, 0xFF, 0x20);
        p += 0x80;
    }
}
