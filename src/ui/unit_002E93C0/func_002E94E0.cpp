typedef float f32;

struct Obj { char pad[0xC0]; f32 unkC0; };

extern "C" f32 func_002E94E0(Obj *arg0) {
    return arg0->unkC0;
}
