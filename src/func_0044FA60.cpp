typedef float f32;

struct Obj { char pad[0x84]; f32 unk84; };

extern "C" f32 func_0044FA60(Obj *arg0) {
    return arg0->unk84;
}
