#include "types.h"
#include "gt4/hException.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

char * func_005C2560(void *);
struct hException__virtual_02_arg1 {
    u8 pad0[0x10];
    s8 *unk10;
};
struct hException__virtual_02_temp_a1 {
    u8 pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s32 *hException__virtual_02(struct hException *arg0, struct hException__virtual_02_arg1 *arg1) {
    s8 *temp_v0;
    s8 *var_a2;
    struct hException__virtual_02_temp_a1 *temp_a1;

    temp_v0 = arg1->unk10;
    temp_a1 = temp_v0 - 0x10;
    var_a2 = temp_v0;
    if (temp_a1->unkC != 0) {
        var_a2 = func_005C2560(temp_a1);
    } else {
        temp_a1->unk8 = (s32) (temp_a1->unk8 + 1);
    }
    arg0->unk0 = (s32) var_a2;
    return &arg0->unk0;
}
