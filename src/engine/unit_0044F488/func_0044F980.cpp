typedef float f32;

struct Obj { char pad[0x4C]; f32 unk4C; };

extern "C" f32 func_0044F980(Obj *arg0) {
    return arg0->unk4C;
}
