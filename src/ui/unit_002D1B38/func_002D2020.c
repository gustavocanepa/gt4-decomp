#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_002D2020_arg0 {
    char pad0[0x20];
    s32 unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
};
struct func_002D2020_temp_v0 {
    char pad0[0xB0];
    s32 unkB0;
};
struct func_002D2020_temp_v0_2 {
    char pad0[0xB0];
    s32 unkB0;
};
struct func_002D2020_temp_v0_3 {
    char pad0[0xB0];
    s32 unkB0;
};
struct func_002D2020_temp_a0 {
    char pad0[0xB0];
    s32 unkB0;
};

void func_002D2020(struct func_002D2020_arg0 *arg0, s32 arg1) {
    struct func_002D2020_temp_a0 *temp_a0;
    struct func_002D2020_temp_v0 *temp_v0;
    struct func_002D2020_temp_v0_2 *temp_v0_2;
    struct func_002D2020_temp_v0_3 *temp_v0_3;

    if (arg0->unk20 != 0) {
        temp_v0 = arg0->unk24;
        if (temp_v0 != NULL) {
            temp_v0->unkB0 = arg1;
        }
        temp_v0_2 = arg0->unk28;
        if (temp_v0_2 != NULL) {
            temp_v0_2->unkB0 = arg1;
        }
        temp_v0_3 = arg0->unk2C;
        if (temp_v0_3 != NULL) {
            temp_v0_3->unkB0 = arg1;
        }
        temp_a0 = arg0->unk30;
        if (temp_a0 != NULL) {
            temp_a0->unkB0 = arg1;
        }
    }
}
