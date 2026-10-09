typedef float f32;

struct Obj { char pad[0xE4]; f32 unkE4; };

extern "C" f32 func_00233D98(Obj *arg0) {
    return arg0->unkE4;
}
