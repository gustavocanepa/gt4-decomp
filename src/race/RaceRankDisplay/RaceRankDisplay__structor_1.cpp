#include "gt4/RaceRankDisplay.h"
typedef int s32;

extern void *RaceRankDisplay__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_003A9758(void *);
extern "C" void *AutomaticFader__fadein(void *, float);

extern "C" void RaceRankDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    ((struct RaceRankDisplay *)arg0)->unk18 = 0x0;
    ((struct RaceRankDisplay *)arg0)->unk1C = 0x0;
    ((struct RaceRankDisplay *)arg0)->unk14 = &RaceRankDisplay__vtable;
    ((struct RaceRankDisplay *)arg0)->unk20 = 0x0;
    func_003A9758((char *)arg0 + 0x24);
    AutomaticFader__fadein((char *)arg0 + 0x24, 0.0f); return;
}
