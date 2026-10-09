typedef float f32;

struct Obj { char pad[0x24]; f32 unk24; };

extern "C" f32 func_0027B3E0(Obj *arg0) {
    return arg0->unk24;
}
