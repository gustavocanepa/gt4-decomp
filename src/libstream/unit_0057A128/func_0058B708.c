/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 memcpy(s32, void *, u32);            /* extern */
s32 func_005A48D8(s32, s32, s32);           /* extern */

struct func_0058B708_temp_s0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
    char pad2C[0x4];
    u32 unk30;
    u32 unk34;
};

struct func_0058B708_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_0058B708(void *arg0) {
    u32 temp_a2;
    u32 temp_v1;
    struct func_0058B708_temp_s0 *temp_s0;

    temp_s0 = arg0 + ((struct func_0058B708_arg0 *)arg0)->unk1C;
    memcpy(temp_s0->unk28, arg0 + temp_s0->unk24, temp_s0->unk30);
    temp_a2 = temp_s0->unk34;
    temp_v1 = temp_s0->unk30;
    if (temp_v1 < temp_a2) {
        func_005A48D8(temp_s0->unk28 + temp_v1, 0, temp_a2 - temp_v1);
    }
}
