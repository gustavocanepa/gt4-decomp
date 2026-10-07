typedef float f32;

struct Obj { char pad[0x50]; f32 unk50; };

extern "C" f32 func_00385818(Obj *arg0) {
    return arg0->unk50;
}
