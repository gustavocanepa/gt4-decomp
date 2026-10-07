typedef float f32;

struct Obj { char pad[0xB4]; f32 unkB4; };

extern "C" f32 func_00200EB8(Obj *arg0) {
    return arg0->unkB4;
}
