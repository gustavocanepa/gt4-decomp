#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct RaceDisplayGeneralTimeEvent__virtual_02_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 unkC;
};

void RaceDisplayDiffEvent__decode(struct RaceDisplayGeneralTimeEvent__virtual_02_arg0 *arg0, u32 arg1) {
    arg0->unk0 = (s32) (arg1 & 0xF);
    arg0->unkC = (s32) ((arg1 >> 4) & 3);
    arg0->unk8 = (s32) ((s32) arg1 >> 6);
}
