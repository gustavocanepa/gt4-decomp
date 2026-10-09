typedef float f32;

struct Obj { char pad[0xE8]; f32 unkE8; };

extern "C" f32 func_00238FE8(Obj *arg0) {
    return arg0->unkE8;
}
