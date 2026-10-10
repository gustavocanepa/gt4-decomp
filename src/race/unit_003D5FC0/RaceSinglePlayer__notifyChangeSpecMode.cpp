#include "gt4/RaceNetRallyBattle.h"
typedef unsigned int u32;

extern "C" void RaceBasic__notifyChangeSpecMode();
extern "C" void RaceInput__setRunMode(void *arg0, u32 arg1);

extern "C" void RaceSinglePlayer__notifyChangeSpecMode(struct RaceNetRallyBattle *arg0) {
    struct RaceNetRallyBattle *s0 = arg0;
    RaceBasic__notifyChangeSpecMode();
    RaceInput__setRunMode((char *)s0 + 0x123CC, s0->unkCC8);
}
