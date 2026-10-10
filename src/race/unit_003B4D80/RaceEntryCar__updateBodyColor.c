#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 SPEC_DATABASE__CarEquipments__getVariationOrder(void *);                          /* extern */

struct func_003B4FD0_temp_s0_2 {
    char pad0[0x4];
    s32 (*unk4)(void *, s32);
};

struct func_003B4FD0_arg0 {
    char pad0[0x2880];
    void *unk2880;
};
struct func_003B4FD0_temp_s1 {
    char pad0[0x8];
    void *unk8;
};
struct func_003B4FD0_temp_s0 {
    char pad0[0x30];
    s16 unk30;
};

void RaceEntryCar__updateBodyColor(void *arg0) {
    void *temp_s0;
    struct func_003B4FD0_temp_s0_2 *temp_s0_2;
    void *temp_s1;
    void *temp_s1_2;

    temp_s1 = ((struct func_003B4FD0_arg0 *)arg0)->unk2880;
    temp_s0 = ((struct func_003B4FD0_temp_s1 *)temp_s1)->unk8;
    temp_s0_2 = temp_s0 + 0x30;
    temp_s1_2 = temp_s1 + ((struct func_003B4FD0_temp_s0 *)temp_s0)->unk30;
    temp_s0_2->unk4(temp_s1_2, SPEC_DATABASE__CarEquipments__getVariationOrder(arg0 + 0x20));
}
