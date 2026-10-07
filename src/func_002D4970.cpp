typedef float f32;

struct Obj { char pad[0xB4]; f32 unkB4; };

extern "C" f32 func_002D4970(Obj *arg0) {
    return arg0->unkB4;
}
