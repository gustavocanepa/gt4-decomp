#include "types.h"
#include "gt4/RaceSplitBattleInformation.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005F28F8();                            /* extern */

extern char RaceSplitBattleInformation__vtable[];
s32 RaceSplitBattleInformation__structor_0(struct RaceSplitBattleInformation *arg0) {
    func_005F28F8();
    arg0->unk118 = 2;
    arg0->unk12C = (s32)RaceSplitBattleInformation__vtable;
}
