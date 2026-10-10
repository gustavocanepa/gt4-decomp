#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_002C1750_temp_v1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_002C1750_temp_v0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_002C1750_arg0 {
    char pad0[0x28];
    f32 unk28;
    char pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    char pad40[0xC];
    f32 unk4C;
};

void func_002C1750(void *arg0) {
    struct func_002C1750_temp_v0 *temp_v0;
    struct func_002C1750_temp_v1 *temp_v1;

    temp_v1 = arg0 + 0x3C;
    temp_v0 = arg0 + 0x28;
    if (temp_v1 != temp_v0) {
        ((struct func_002C1750_arg0 *)arg0)->unk3C = (f32) ((struct func_002C1750_arg0 *)arg0)->unk28;
        temp_v1->unk4 = (f32) temp_v0->unk4;
        temp_v1->unk8 = (f32) temp_v0->unk8;
        temp_v1->unkC = (f32) temp_v0->unkC;
    }
    ((struct func_002C1750_arg0 *)arg0)->unk4C = (f32) ((struct func_002C1750_arg0 *)arg0)->unk38;
}
