typedef float f32;

struct Part { char b[0x20]; };
struct Obj { char pad[4]; Part a; Part b; };
extern "C" void Oscillator__update(Part *, f32);
extern "C" void AutomaticFader__update(Part *, f32);

extern "C" void GTMiniLogo__update(Obj *o) {
    f32 dt = 1.0f / 60.0f;
    Oscillator__update(&o->a, dt);
    AutomaticFader__update(&o->b, dt);
}
