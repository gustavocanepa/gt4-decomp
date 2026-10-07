typedef float f32;

struct Obj { char pad[0x78]; f32 unk78; };

extern "C" f32 func_0044FA30(Obj *arg0) {
    return arg0->unk78;
}
