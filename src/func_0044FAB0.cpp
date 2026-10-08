typedef float f32;

struct Obj { char pad[0x9C]; f32 unk9C; };

extern "C" f32 func_0044FAB0(Obj *arg0) {
    return arg0->unk9C;
}
