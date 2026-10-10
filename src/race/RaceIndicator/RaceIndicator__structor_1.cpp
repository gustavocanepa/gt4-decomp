#include "gt4/RaceIndicator.h"
typedef int s32;

extern void *RaceIndicator__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_003A9608(void *);
extern "C" void *Oscillator__setCycle(void *, float, float);
extern "C" void *Oscillator__setWaveform(void *, float, float);
extern "C" void *Oscillator__setCount(void *, s32, s32);

extern "C" void RaceIndicator__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    ((struct RaceIndicator *)arg0)->unk14 = &RaceIndicator__vtable;
    func_003A9608((char *)arg0 + 0x18);
    ((struct RaceIndicator *)arg0)->unk38 = (void *)(-0x7f000001);
    ((struct RaceIndicator *)arg0)->unk3C = 0x0;
    ((struct RaceIndicator *)arg0)->unk40 = 0x0;
    Oscillator__setCycle((char *)arg0 + 0x18, 0.199999991804f, 0.500000014901f);
    Oscillator__setWaveform((char *)arg0 + 0x18, 0.0f, 0.0699999947101f);
    Oscillator__setCount((char *)arg0 + 0x18, -0x1, 0x0); return;
}
