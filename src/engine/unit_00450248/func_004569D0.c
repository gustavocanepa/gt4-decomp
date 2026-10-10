#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004569D0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};
struct func_004569D0_arg1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

s32 func_004569D0(struct func_004569D0_arg0 *arg0, struct func_004569D0_arg1 *arg1) {
    arg0->unk0 = (s32) arg1->unk4;
    arg0->unk4 = (s32) arg1->unk8;
    arg0->unk8 = (s32) arg1->unkC;
}
