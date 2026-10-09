typedef float f32;

struct Obj { char pad[0x68]; f32 unk68; };

extern "C" f32 func_0044F9F0(Obj *arg0) {
    return arg0->unk68;
}
