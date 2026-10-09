typedef float f32;

struct Obj { char pad[0x780]; f32 unk780; };

extern "C" f32 func_00557EB0(Obj *arg0) {
    return arg0->unk780;
}
