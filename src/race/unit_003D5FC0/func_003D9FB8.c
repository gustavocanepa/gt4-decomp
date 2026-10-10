#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003D9FB8_arg0 {
    char pad0[0x74];
    s32 unk74;
    char pad78[0x18];
    s32 unk90;
    char pad94[0x8];
    s32 unk9C;
    char padA0[0x4];
    s32 unkA4;
};

void func_003D9FB8(struct func_003D9FB8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk74;
    if (temp_v0 < 3) {
        arg0->unk74 = (s32) (temp_v0 + 1);
        arg0->unk9C = 2;
        arg0->unkA4 = (s32) ((arg0->unkA4 & ~0xFF) | 1);
    } else {
        arg0->unk9C = 3;
    }
    arg0->unk90 = 0;
}
