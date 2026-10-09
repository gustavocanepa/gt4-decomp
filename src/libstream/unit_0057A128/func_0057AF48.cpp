typedef float f32;

struct Obj {
    f32 unk0;
    char pad4[4];
    f32 unk8;
};

extern "C" struct Obj *func_0057AF48(struct Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk0 = arg0->unk0 + (fparg0 - arg0->unk8) * fparg1;
    return arg0;
}
