#include "types.h"
#include "gt4/RaceNetBattle.h"
void *memcpy(void *, const void *, unsigned int);

s32 RaceBasic__getReplayPauseExit(struct RaceNetBattle *arg0) {
    return (u32) arg0->unkCC8_u32 >= 2U;
}
