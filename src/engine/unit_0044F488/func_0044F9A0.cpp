typedef float f32;

struct Obj { char pad[0x58]; f32 unk58; };

extern "C" f32 func_0044F9A0(Obj *arg0) {
    return arg0->unk58;
}
