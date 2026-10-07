typedef float f32;

struct Obj { char pad[0xC]; f32 unkC; };

extern "C" f32 func_0044F880(Obj *arg0) {
    return arg0->unkC;
}
