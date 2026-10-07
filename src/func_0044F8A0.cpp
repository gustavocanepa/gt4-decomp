typedef float f32;

struct Obj { char pad[0x14]; f32 unk14; };

extern "C" f32 func_0044F8A0(Obj *arg0) {
    return arg0->unk14;
}
