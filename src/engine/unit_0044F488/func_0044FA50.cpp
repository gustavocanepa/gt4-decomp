typedef float f32;

struct Obj { char pad[0x80]; f32 unk80; };

extern "C" f32 func_0044FA50(Obj *arg0) {
    return arg0->unk80;
}
