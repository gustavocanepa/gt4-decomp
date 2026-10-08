typedef float f32;

struct Obj { char pad[0xC8]; f32 unkC8; };

extern "C" f32 func_002B85A0(Obj *arg0) {
    return arg0->unkC8;
}
