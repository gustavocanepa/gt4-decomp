#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00572278_arg1 {
    char pad0[0x4];
    u32 unk4;
};
struct func_00572278_arg0 {
    void *unk0;
    u32 unk4;
    s32 unk8;
};
struct func_00572278_temp_v1 {
    s32 unk0;
    u32 unk4;
};

void func_00572278(struct func_00572278_arg0 *arg0, struct func_00572278_arg1 *arg1) {
    u32 temp_a1;
    struct func_00572278_temp_v1 *temp_v1;

    temp_a1 = arg1->unk4;
    temp_v1 = arg0->unk0;
    arg0->unk8 = temp_v1;
    temp_v1->unk0 = 0;
    temp_v1->unk4 = temp_a1;
    if (temp_a1 < (u32) arg0->unk4) {
        *(s32 *)temp_a1 = temp_v1;
    }
}
