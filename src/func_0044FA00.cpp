typedef float f32;

struct Obj { char pad[0x6C]; f32 unk6C; };

extern "C" f32 func_0044FA00(Obj *arg0) {
    return arg0->unk6C;
}
