typedef float f32;

struct Obj {
    int unk0;
    f32 unk4;
    int unk8;
    f32 unkC;
};

extern "C" Obj *func_004222A0(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk4 = fparg0;
    arg0->unkC = fparg1;
    arg0->unk0 = 0;
    arg0->unk8 = 0;
    return arg0;
}
