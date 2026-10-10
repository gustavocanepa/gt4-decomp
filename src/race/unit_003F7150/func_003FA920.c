#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct DynamicsConductor {
    void * unk0;
    char unk_4[0x90];
    f32 unk94;
};
f32 func_0034C230(struct DynamicsConductor *);
struct func_003FA920_temp_a1 {
    char pad0[0x4A4];
    f32 unk4A4;
    char pad4A8[0x4];
    s16 unk4AC;
    char pad4AE[0x2];
    u8 unk4B0;
};

struct func_003FA920_arg0 {
    char pad0[0x4];
    struct DynamicsConductor *unk4;
};

f32 func_003FA920(void *arg0) {
    f32 temp_f20;
    f32 var_f0;
    s32 temp_s0;
    struct func_003FA920_temp_a1 *temp_a1;

    temp_a1 = arg0 + 0x104;
    var_f0 = 0x0.0p+0f;
    temp_s0 = temp_a1->unk4AC - temp_a1->unk4B0;
    if (temp_s0 > 0) {
        temp_f20 = temp_a1->unk4A4;
        var_f0 = temp_f20 + (func_0034C230(((struct func_003FA920_arg0 *)arg0)->unk4) * (f32) (temp_s0 - 1));
    }
    return var_f0;
}
