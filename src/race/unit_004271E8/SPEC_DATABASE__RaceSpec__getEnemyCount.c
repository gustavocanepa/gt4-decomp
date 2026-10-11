#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 SPEC_DATABASE__RaceSpec__loadEnemyInfo(void *, s64);
struct func_004473B0_arg0 {
    char pad0[0x98];
    s64 unk98;
    char padA0[0x8];
    s32 *unkA8;
};

s32 SPEC_DATABASE__RaceSpec__getEnemyCount(struct func_004473B0_arg0 *arg0) {
    if (arg0->unkA8 == NULL) {
        if (SPEC_DATABASE__RaceSpec__loadEnemyInfo(arg0, arg0->unk98) != 0) {
            goto block_6;
        }
        return -1;
    }
block_6:
    return *arg0->unkA8;
}
