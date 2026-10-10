#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct mPop {
    s32 unk0;
    void * unk4;
    void * unk8;
    char unk_C[0xC];
    s32 unk18;
    s32 unk1C;
};
struct mPop__virtual_08_temp_v1 {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x8];
    s32 unk20;
};

struct mPop__virtual_08_arg1 {
    char pad0[0x2C];
    void *unk2C;
    s32 unk30;
};

void mPop__execute(struct mPop *arg0, void *arg1) {
    s32 *temp_a0;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    struct mPop__virtual_08_temp_v1 *temp_v1;

    temp_v1 = ((struct mPop__virtual_08_arg1 *)arg1)->unk2C;
    temp_v0 = temp_v1->unk20 - 1;
    temp_a0 = temp_v1->unk14 + (temp_v0 * 4);
    temp_v1->unk20 = temp_v0;
    if ((arg1 + 0x30) != temp_a0) {
        temp_s0 = *temp_a0;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0_2 = ((struct mPop__virtual_08_arg1 *)arg1)->unk30;
        if (temp_v0_2 != 0) {
            func_003285F8(temp_v0_2);
        }
        ((struct mPop__virtual_08_arg1 *)arg1)->unk30 = temp_s0;
    }
}
