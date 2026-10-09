typedef float f32;

struct Obj { char pad[0x5C]; f32 unk5C; };

extern "C" f32 func_0044F9C0(Obj *arg0) {
    return arg0->unk5C;
}
