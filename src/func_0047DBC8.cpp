typedef float f32;

struct Obj { char pad[0x38]; f32 unk38; };

extern "C" f32 func_0047DBC8(Obj *arg0) {
    return arg0->unk38;
}
