#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003F84E0_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};
struct func_003F84E0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_003F84E0(struct func_003F84E0_arg0 *arg0, struct func_003F84E0_arg1 *arg1) {
    arg1->unk0 = (s32) arg0->unk0;
    arg1->unk4 = (s32) arg0->unk4;
    arg1->unk8 = (s32) arg0->unk8;
    arg1->unkC = (s32) arg0->unkC;
    arg1->unk10 = (s32) arg0->unk10;
}
