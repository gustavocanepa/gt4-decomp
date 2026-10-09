typedef float f32;

struct Obj { char pad[0x8C]; f32 unk8C; };

extern "C" f32 func_0044FA80(Obj *arg0) {
    return arg0->unk8C;
}
