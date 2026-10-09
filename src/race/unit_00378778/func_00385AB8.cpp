typedef float f32;

struct Obj { char pad[0xE0]; f32 unkE0; };

extern "C" f32 func_00385AB8(Obj *arg0) {
    return arg0->unkE0;
}
