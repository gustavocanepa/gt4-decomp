typedef float f32;

struct Obj { char pad[0x34]; f32 unk34; };

extern "C" f32 func_0047DBB8(Obj *arg0) {
    return arg0->unk34;
}
