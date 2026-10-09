typedef int s32;
typedef float f32;

struct Obj {
    f32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
};

extern "C" Obj *func_00422288(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk0 = fparg0;
    arg0->unkC = fparg1;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    return arg0;
}
