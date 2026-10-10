typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Part { char b[0x20]; };
struct Obj { char pad[0x18]; u8 f18; char pad19[3]; Part p; };
extern "C" void Oscillator__update(Part *, f32);
extern "C" void Oscillator__setCount(Part *, s32, s32);

extern "C" void RaceShiftTimingLampDisplay__update(Obj *o, f32 dt) {
    Oscillator__update(&o->p, dt);
    Oscillator__setCount(&o->p, o->f18 ? -1 : 0, 0);
}
