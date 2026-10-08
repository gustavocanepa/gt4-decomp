typedef float f32;

struct Obj { char pad[0x5E0]; f32 unk5E0; };

extern "C" f32 func_00354EB0(Obj *arg0) {
    return arg0->unk5E0;
}
