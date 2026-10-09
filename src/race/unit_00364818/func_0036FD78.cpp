typedef float f32;

struct Obj {
    char pad[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

extern "C" void func_0036FD78(Obj *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    arg0->unk8 = fparg0;
    arg0->unkC = fparg1;
    arg0->unk10 = fparg2;
}
