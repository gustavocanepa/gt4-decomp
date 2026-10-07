typedef float f32;

struct Obj { char pad[0xC8]; f32 unkC8; };

extern "C" f32 func_00238F78(Obj *arg0) {
    return arg0->unkC8;
}
