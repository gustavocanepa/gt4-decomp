#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004427B8_arg1 {
    char pad0[0x20];
    s16 unk20;
    char pad22[0x2];
    u8 unk24;
};
struct func_004427B8_arg2 {
    u16 unk0;
    char pad2[0x3];
    u8 unk5;
};

void func_004427B8(s32 arg0, struct func_004427B8_arg1 *arg1, struct func_004427B8_arg2 *arg2) {
    arg1->unk20 = (s16) ((s32) (arg1->unk20 * arg2->unk0) / 1000);
    arg1->unk24 = (u8) ((s32) (arg1->unk24 * arg2->unk5) / 100);
}
