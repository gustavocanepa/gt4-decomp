#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0047E1B8_arg2 {
    f32 unk0;
    f32 unk4;
};
struct func_0047E1B8_arg0 {
    f32 unk0;
    f32 unk4;
    char pad8[0x8];
    f32 unk10;
    f32 unk14;
    char pad18[0x18];
    f32 unk30;
    f32 unk34;
};
struct func_0047E1B8_arg1 {
    f32 unk0;
    f32 unk4;
};

void func_0047E1B8(struct func_0047E1B8_arg0 *arg0, struct func_0047E1B8_arg1 *arg1, struct func_0047E1B8_arg2 *arg2) {
    arg2->unk0 = (f32) ((arg0->unk0 * arg1->unk0) + (arg0->unk10 * arg1->unk4) + arg0->unk30);
    arg2->unk4 = (f32) ((arg0->unk4 * arg1->unk0) + (arg0->unk14 * arg1->unk4) + arg0->unk34);
}
