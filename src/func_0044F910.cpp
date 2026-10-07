typedef float f32;

struct Obj { char pad[0x30]; f32 unk30; };

extern "C" f32 func_0044F910(Obj *arg0) {
    return arg0->unk30;
}
