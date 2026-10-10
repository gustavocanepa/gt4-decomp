/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00590B60_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x4];
    s32 unk18;
};

void func_00590B60(struct func_00590B60_arg0 *arg0) {
    arg0->unk18 = 0;
    arg0->unk10 = (s32) (arg0->unk10 & 0xFFFFFFFE);
}
