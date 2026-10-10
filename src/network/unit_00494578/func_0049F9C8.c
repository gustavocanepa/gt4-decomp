/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0049F9C8_arg0 {
    char pad0[0x1F8];
    void *unk1F8;
};

struct func_0049F9C8_temp_a3 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_0049F9C8(struct func_0049F9C8_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a2;
    void *temp_a3;

    temp_a3 = arg0->unk1F8;
    temp_a2 = (arg2 + 3) & ~3;
    ((struct func_0049F9C8_temp_a3 *)temp_a3)->unk0 = (s32) ((temp_a2 >> 2) | 0x30000000);
    ((struct func_0049F9C8_temp_a3 *)temp_a3)->unk4 = (s32) (arg1 & 0x0FFFFFFF);
    ((struct func_0049F9C8_temp_a3 *)temp_a3)->unkC = (s32) ((temp_a2 << 0x10) | 0x6E00C080);
    ((struct func_0049F9C8_temp_a3 *)temp_a3)->unk8 = 0;
    arg0->unk1F8 = (void *) (temp_a3 + 0x10);
}
