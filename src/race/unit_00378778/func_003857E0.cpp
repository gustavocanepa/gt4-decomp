typedef float f32;

struct Obj { char pad[0x44]; f32 unk44; };

extern "C" f32 func_003857E0(Obj *arg0) {
    return arg0->unk44;
}
