typedef float f32;

struct Obj { char pad[0x5D0]; f32 unk5D0; };

extern "C" f32 func_00354E58(Obj *arg0) {
    return arg0->unk5D0;
}
