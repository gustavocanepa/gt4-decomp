typedef float f32;

struct Obj { char pad[0x1C]; f32 unk1C; };

extern "C" f32 func_003856F8(Obj *arg0) {
    return arg0->unk1C;
}
