typedef int s32;

extern void *RaceSuggestedGearDisplay__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_003A9608(void *);
extern "C" void *func_003A9758(void *);
extern "C" void *Oscillator__setCycle(void *, float, float);
extern "C" void *Oscillator__setWaveform(void *, float, float);

extern "C" void RaceSuggestedGearDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = &RaceSuggestedGearDisplay__vtable;
    func_003A9608((char *)arg0 + 0x18);
    func_003A9758((char *)arg0 + 0x38);
    *(char *)((char *)arg0 + 0x54) = 0x0;
    *(char *)((char *)arg0 + 0x55) = 0x0;
    *(void **)((char *)arg0 + 0x54) = (void *)(*(unsigned short *)((char *)arg0 + 0x54));
    Oscillator__setCycle((char *)arg0 + 0x18, 0.149999994785f, 0.329999990761f);
    Oscillator__setWaveform((char *)arg0 + 0x18, 0.0200000000186f, 0.0599999995902f); return;
}
