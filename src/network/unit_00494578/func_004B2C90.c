/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004B2C90_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s64 unk10;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
};
struct func_004B2C90_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s64 unk10;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
};

void *func_004B2C90(struct func_004B2C90_arg0 *arg0, struct func_004B2C90_arg1 *arg1) {
    arg0->unk0 = (s32) arg1->unk0;
    arg0->unk4 = (s32) arg1->unk4;
    arg0->unk8 = (s32) arg1->unk8;
    arg0->unk10 = (s64) arg1->unk10;
    arg0->unk18 = (s32) arg1->unk18;
    arg0->unk1C = (s32) arg1->unk1C;
    arg0->unk20 = (u8) arg1->unk20;
    return arg0;
}
