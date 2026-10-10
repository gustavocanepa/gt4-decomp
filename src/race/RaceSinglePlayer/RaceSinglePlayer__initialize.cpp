#include "gt4/RaceSinglePlayer.h"
typedef unsigned int u32;

extern "C" void RaceBasic__initialize();
extern "C" void RaceInput__setRunMode(void *arg0, u32 arg1);

extern "C" void RaceSinglePlayer__initialize(struct RaceSinglePlayer *arg0) {
    struct RaceSinglePlayer *s0 = arg0;
    RaceBasic__initialize();
    RaceInput__setRunMode((char *)s0 + 0x123CC, s0->unkCC8);
}
