typedef float f32;

struct Obj { char pad[0xCC]; f32 unkCC; };

extern "C" f32 func_00238F90(Obj *arg0) {
    return arg0->unkCC;
}
