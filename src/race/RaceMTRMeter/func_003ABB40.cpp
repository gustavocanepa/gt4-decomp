struct Obj {
    char pad[0x30];
    int counters[6];
    unsigned char flag48;
    unsigned char flag49;
    char pad4A[2];
    char filter[0x20];
};

extern "C" void Oscillator__setCycle(void *f, float a, float b);
extern "C" void Oscillator__setWaveform(void *f, float a, float b);
extern "C" void Oscillator__setCount(void *f, int a, int b);

extern "C" void func_003ABB40(Obj *o) {
    o->counters[0] = 0;
    o->counters[1] = 0;
    o->counters[2] = 0;
    o->counters[3] = 0;
    o->counters[4] = 0;
    o->counters[5] = 0;
    o->flag48 = 0;
    o->flag49 = 0;
    Oscillator__setCycle(o->filter, 0x1.999998p-3f, 0.5f);
    Oscillator__setWaveform(o->filter, 0x1.999998p-5f, 0x1.999998p-4f);
    Oscillator__setCount(o->filter, 0, 0);
}
