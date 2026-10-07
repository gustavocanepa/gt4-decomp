typedef float f32;

struct Struct_0020C290 {
    char pad0[0x24];
    f32 unk24;
};

extern "C" void func_0020C290(struct Struct_0020C290 *arg0, f32 fparg0) {
    arg0->unk24 = fparg0;
    if (!(fparg0 >= 0.0f)) {
        arg0->unk24 = -fparg0;
    }
}
