typedef float f32;

struct Obj00486AD0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" f32 func_0048EB60(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void func_00489668(Obj00486AD0 *arg0) {
    func_0048EB60(arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC);
}
