typedef float f32;

struct Obj { char pad[0x2C]; f32 unk2C; };

extern "C" f32 func_0044F900(Obj *arg0) {
    return arg0->unk2C;
}
