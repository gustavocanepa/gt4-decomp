typedef float f32;

struct Obj { char pad[0x5D4]; f32 unk5D4; };

extern "C" f32 func_00354E60(Obj *arg0) {
    return arg0->unk5D4;
}
