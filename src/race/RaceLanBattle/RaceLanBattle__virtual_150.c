#include "types.h"
#include "gt4/RaceLanBattle.h"
void *memcpy(void *, const void *, unsigned int);

void RaceLanBattle__virtual_150(struct RaceLanBattle *arg0) {
    arg0->unkF38C = 1;
    arg0->unkF370 = (s32) (arg0->unkF370 | 0x10);
}
