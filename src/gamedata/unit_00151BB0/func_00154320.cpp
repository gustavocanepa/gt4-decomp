typedef float f32;

struct Obj {
    char pad[0x4C];
    f32 unk4C;
    f32 unk50;
};

extern "C" void func_00154320(Obj *arg0, f32 fparg0) {
    arg0->unk4C = fparg0;
    arg0->unk50 = fparg0;
}
