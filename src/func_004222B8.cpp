typedef int s32;
typedef float f32;

struct Obj {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" Obj *func_004222B8(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk8 = fparg0;
    arg0->unkC = fparg1;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    return arg0;
}
