#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0046B108(s32, f32, f32, f32);          /* extern */

struct func_004639B0_arg0 {
    char pad0[0xE8];
    void *unkE8;
    s32 unkEC;
};
struct func_004639B0_temp_v0_2 {
    char pad0[0x4];
    f32 unk4;
    char pad8[0x49C];
    f32 unk4A4;
};

struct func_004639B0_temp_v0 {
    char pad0[0x104];
    f32 unk104;
};

void func_004639B0(struct func_004639B0_arg0 *arg0) {
    void *temp_v0;
    struct func_004639B0_temp_v0_2 *temp_v0_2;

    temp_v0 = arg0->unkE8;
    temp_v0_2 = temp_v0 + 0x104;
    func_0046B108(arg0->unkEC, ((struct func_004639B0_temp_v0 *)temp_v0)->unk104, temp_v0_2->unk4, temp_v0_2->unk4A4);
}
