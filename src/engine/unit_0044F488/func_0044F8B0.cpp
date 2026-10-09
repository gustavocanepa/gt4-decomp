typedef float f32;

struct Obj { char pad[0x18]; f32 unk18; };

extern "C" f32 func_0044F8B0(Obj *arg0) {
    return arg0->unk18;
}
