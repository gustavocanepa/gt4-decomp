typedef float f32;

struct Vec6 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

extern "C" void func_003EFCE8(Vec6 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5) {
    arg0->unk0 = fparg0;
    arg0->unk4 = fparg1;
    arg0->unk8 = fparg2;
    arg0->unkC = fparg3;
    arg0->unk10 = fparg4;
    arg0->unk14 = fparg5;
}
