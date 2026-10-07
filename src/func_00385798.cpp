typedef float f32;

struct Obj { char pad[0x48]; f32 unk48; };

extern "C" f32 func_00385798(Obj *arg0) {
    return arg0->unk48;
}
