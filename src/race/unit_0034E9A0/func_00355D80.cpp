typedef float f32;

struct Obj { char pad[0x788]; f32 unk788; };

extern "C" f32 func_00355D80(Obj *arg0) {
    return arg0->unk788;
}
