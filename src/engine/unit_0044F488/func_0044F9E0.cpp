typedef float f32;

struct Obj { char pad[0x64]; f32 unk64; };

extern "C" f32 func_0044F9E0(Obj *arg0) {
    return arg0->unk64;
}
