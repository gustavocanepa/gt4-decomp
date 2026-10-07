typedef float f32;

struct Obj { char pad[0x40]; f32 unk40; };

extern "C" f32 func_0044F950(Obj *arg0) {
    return arg0->unk40;
}
