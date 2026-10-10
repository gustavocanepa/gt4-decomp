#include "gt4/RaceSinglePlayer.h"
typedef unsigned int u32;

extern "C" void RaceBasicWithRaceDisplay__virtual_37();
extern "C" void func_00426BF8(void *arg0, u32 arg1);

extern "C" void RaceSinglePlayer__virtual_37(struct RaceSinglePlayer *arg0) {
    struct RaceSinglePlayer *s0 = arg0;
    RaceBasicWithRaceDisplay__virtual_37();
    func_00426BF8((char *)s0 + 0x123CC, s0->unkCC8);
}
