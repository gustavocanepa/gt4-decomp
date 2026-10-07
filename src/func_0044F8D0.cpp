typedef float f32;

struct Obj { char pad[0x20]; f32 unk20; };

extern "C" f32 func_0044F8D0(Obj *arg0) {
    return arg0->unk20;
}
