#include "gt4/RaceNetBattleInformation.h"
typedef long long s64;

extern "C" s64 func_00447188(struct RaceNetBattleInformation *arg0);

extern "C" void RaceNetBattleInformation__virtual_20(struct RaceNetBattleInformation *arg0) {
    struct RaceNetBattleInformation *s0 = arg0;

    func_00447188(arg0);
    s0->unk110 = s0->unk98;
}
