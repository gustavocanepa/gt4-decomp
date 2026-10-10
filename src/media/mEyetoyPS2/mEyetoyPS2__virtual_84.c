#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void *func_00578CF0(s32, s32);
struct mEyetoyPS2__virtual_84_arg0 {
    char pad0[0x14];
    void *unk14;
    void *unk18;
    void *unk1C;
};
struct mEyetoyPS2__virtual_84_temp_a1 {
    char pad0[0x264];
    s32 unk264;
    s32 unk268;
};

void mEyetoyPS2__virtual_84(struct mEyetoyPS2__virtual_84_arg0 *arg0) {
    struct mEyetoyPS2__virtual_84_temp_a1 *temp_a1;
    if (arg0->unk18 == 0) {
        arg0->unk18 = func_00578CF0(0x80, 0x4B080);
    }
    if (arg0->unk1C == 0) {
        arg0->unk1C = func_00578CF0(0x80, 0x4B080);
    }
    temp_a1 = arg0->unk14;
    if (temp_a1 != NULL) {
        temp_a1->unk264 = (s32) arg0->unk18;
        temp_a1->unk268 = (s32) arg0->unk1C;
    }
}
