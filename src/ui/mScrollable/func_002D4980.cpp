typedef float f32;

struct Obj { char pad[0xB8]; f32 unkB8; };

extern "C" f32 func_002D4980(Obj *arg0) {
    return arg0->unkB8;
}
