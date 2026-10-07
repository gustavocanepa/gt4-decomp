typedef float f32;

struct Obj { char pad[0x654]; f32 unk654; };

extern "C" f32 func_003451A0(Obj *arg0) {
    return arg0->unk654;
}
