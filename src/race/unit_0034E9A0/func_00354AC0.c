#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00354AC0_temp_v0 {
    char pad0[0x4D0];
    f32 unk4D0;
    f32 unk4D4;
    f32 unk4D8;
};
struct func_00354AC0_temp_v1 {
    char pad0[0x48];
    f32 unk48;
    f32 unk4C;
};

struct func_00354AC0_arg0 {
    char pad0[0x10];
    void *unk10;
};

void func_00354AC0(void *arg0) {
    f32 temp_f2;
    struct func_00354AC0_temp_v0 *temp_v0;
    struct func_00354AC0_temp_v1 *temp_v1;

    temp_v0 = arg0 + 0x104;
    temp_v1 = ((struct func_00354AC0_arg0 *)arg0)->unk10;
    temp_f2 = temp_v0->unk4D0 * 0.73999995f;
    temp_v0->unk4D4 = (f32) (temp_v1->unk48 + temp_f2);
    temp_v0->unk4D8 = (f32) (temp_v1->unk4C + temp_f2);
}
