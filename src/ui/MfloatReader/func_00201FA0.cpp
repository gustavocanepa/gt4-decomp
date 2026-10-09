typedef float f32;

struct Obj { char pad[0x4]; f32 unk4; };

extern "C" f32 func_00201FA0(Obj *arg0) {
    return arg0->unk4;
}
