#include "gt4/RaceOnboardPanel.h"
typedef int s32;
typedef short s16;
typedef float f32;

extern "C" void RaceOnboardPanel__setSpeed(struct RaceOnboardPanel *arg0, f32 fparg0) {
    arg0->unk84 = fparg0;
    arg0->unkA1A = (s16)(s32)(fparg0 + 0.5f);
}
