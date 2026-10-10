#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004A1F60_arg0 {
    char pad0[0x1F8];
    void *unk1F8;
};

struct func_004A1F60_temp_a2 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

s32 func_004A1F60(struct func_004A1F60_arg0 *arg0, s32 arg1) {
    s32 var_a1;
    void *temp_a2;

    temp_a2 = arg0->unk1F8;
    arg0->unk1F8 = (void *) (temp_a2 + 0x10);
    ((struct func_004A1F60_temp_a2 *)temp_a2)->unk0 = 0x10000000;
    ((struct func_004A1F60_temp_a2 *)temp_a2)->unk4 = 0;
    ((struct func_004A1F60_temp_a2 *)temp_a2)->unk8 = 0;
    if (arg1 != 0) {
        var_a1 = arg1 | 0x91000000;
    } else {
        var_a1 = 0;
    }
    ((struct func_004A1F60_temp_a2 *)temp_a2)->unkC = var_a1;
    return temp_a2 + 0xC;
}
