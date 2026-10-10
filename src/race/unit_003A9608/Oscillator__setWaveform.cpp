typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
};

extern "C" void Oscillator__setWaveform(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk10 = 1.0f / fparg0;
    arg0->unk14 = 1.0f / fparg1;
}
