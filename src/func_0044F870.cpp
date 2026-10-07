typedef float f32;

struct Obj { char pad[0x8]; f32 unk8; };

extern "C" f32 func_0044F870(Obj *arg0) {
    return arg0->unk8;
}
