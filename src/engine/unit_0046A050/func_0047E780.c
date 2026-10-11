#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0047E780_arg0 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s32 unk4;
};

void func_0047E780(struct func_0047E780_arg0 *arg0, u32 arg1) {
    arg0->unk0 = (s8) ((s32) ((arg1 & 0xFF) << 7) / 255);
    arg0->unk1 = (s8) ((s32) ((arg1 >> 1) & 0x7F80) / 255);
    arg0->unk2 = (s8) ((s32) ((arg1 >> 9) & 0x7F80) / 255);
    arg0->unk3 = (s8) (arg1 >> 0x18);
    arg0->unk4 = 0;
}
