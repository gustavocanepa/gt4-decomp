typedef float f32;

struct Obj { char pad[0x248]; f32 unk248; };

extern "C" f32 func_001C2FA0(Obj *arg0) {
    return arg0->unk248;
}
