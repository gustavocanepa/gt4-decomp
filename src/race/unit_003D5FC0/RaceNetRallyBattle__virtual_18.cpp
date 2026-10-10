#include "gt4/RaceNetRallyBattle.h"
typedef unsigned int u32;

extern "C" void RaceNetBattle__virtual_18();
extern "C" void func_00426BF8(void *arg0, u32 arg1);

extern "C" void RaceNetRallyBattle__virtual_18(struct RaceNetRallyBattle *arg0) {
    struct RaceNetRallyBattle *s0 = arg0;
    RaceNetBattle__virtual_18();
    func_00426BF8((char *)s0 + 0x123CC, s0->unkCC8);
}
