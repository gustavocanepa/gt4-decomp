#include "types.h"
#include "gt4/mEyetoyPS2.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00575DA0(s32);
struct mEyetoyPS2__virtual_85_temp_v0 {
    char pad0[0x264];
    s32 unk264;
    s32 unk268;
};

void mEyetoyPS2__virtual_85(struct mEyetoyPS2 *arg0) {
    s32 temp_v0_2;
    s32 temp_v0_3;
    struct mEyetoyPS2__virtual_85_temp_v0 *temp_v0;
    temp_v0 = arg0->unk14_pvoid;
    if (temp_v0 != NULL) {
        temp_v0->unk264 = 0; temp_v0->unk268 = 0;
    }
    temp_v0_2 = arg0->unk18;
    if (temp_v0_2 != 0) {
        func_00575DA0(temp_v0_2);
        arg0->unk18 = 0;
    }
    temp_v0_3 = arg0->unk1C;
    if (temp_v0_3 != 0) {
        func_00575DA0(temp_v0_3);
        arg0->unk1C = 0;
    }
}
