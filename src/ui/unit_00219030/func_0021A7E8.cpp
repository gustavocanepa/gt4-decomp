typedef float f32;

struct Obj { char pad[0x24]; f32 unk24; };

extern "C" f32 func_0021A7E8(Obj *arg0) {
    return arg0->unk24;
}
