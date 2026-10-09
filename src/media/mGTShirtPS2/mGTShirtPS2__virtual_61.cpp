typedef float f32;

struct mGTShirtPS2 {
    char pad[0x244];
    f32 unk244;
};

extern "C" void func_001C3958(mGTShirtPS2 *arg0);

extern "C" void mGTShirtPS2__virtual_61(mGTShirtPS2 *arg0, f32 fparg0) {
    arg0->unk244 = fparg0;
    func_001C3958(arg0);
}
