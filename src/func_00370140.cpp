typedef float f32;

struct Obj {
    char pad[0x3C];
    f32 unk3C;
};

extern "C" f32 func_00370010(Obj *arg0, f32 arg1);

extern "C" f32 func_00370140(Obj *arg0) {
    return func_00370010(arg0, arg0->unk3C);
}
