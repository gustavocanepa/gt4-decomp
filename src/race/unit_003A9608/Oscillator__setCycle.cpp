typedef float f32;

struct Obj {
    char pad[8];
    f32 unk8;
    f32 unkC;
};

extern "C" void Oscillator__setCycle(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk8 = fparg0;
    arg0->unkC = fparg1;
}
