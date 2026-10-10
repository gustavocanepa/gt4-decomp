#include "gt4/RaceShiftTimingLampDisplay.h"
typedef int s32;

extern void *RaceShiftTimingLampDisplay__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_003A9608(void *);
extern "C" void *Oscillator__setCycle(void *, float, float);
extern "C" void *Oscillator__setWaveform(void *, float, float);

extern "C" void RaceShiftTimingLampDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    ((struct RaceShiftTimingLampDisplay *)arg0)->unk14 = &RaceShiftTimingLampDisplay__vtable;
    func_003A9608((char *)arg0 + 0x1c);
    Oscillator__setCycle((char *)arg0 + 0x1c, 0.149999994785f, 0.199999991804f);
    Oscillator__setWaveform((char *)arg0 + 0x1c, 0.0200000000186f, 0.149999994785f); return;
}
