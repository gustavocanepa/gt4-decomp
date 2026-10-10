#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00851180[];
struct func_004B2CD0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s8 unk10;
};

void func_004B2CD0(struct func_004B2CD0_arg0 *arg0) {
    arg0->unk10 = 1;
    arg0->unk4 = -1;
    arg0->unk8 = -1;
    arg0->unkC = -1;
    arg0->unk0 = (s32)D_00851180;
}
