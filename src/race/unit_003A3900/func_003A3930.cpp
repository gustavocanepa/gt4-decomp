struct Anim {
    int state;
    float speed;
    char pad[0x20 - 8];
};
extern "C" void Oscillator__setCycle(Anim *a, float x, float y);
extern "C" void Oscillator__setWaveform(Anim *a, float x, float y);
extern "C" void Oscillator__setCount(Anim *a, int i, int j);
extern "C" void AutomaticFader__reset(void *p);
struct Obj {
    int m0;
    Anim anim;
    char m24[4];
};

extern "C" void func_003A3930(Obj *o)
{
    Anim *a = &o->anim;
    Oscillator__setCycle(a, 60.0f, 0.5f);
    Oscillator__setWaveform(a, 3.0f, 3.0f);
    Oscillator__setCount(a, -1, 0);
    a->speed = 54.0f;
    a->state = 0;
    AutomaticFader__reset(o->m24);
}
