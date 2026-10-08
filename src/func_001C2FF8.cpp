typedef float f32;

struct mGTShirtPS2 {
    char pad[0x250];
    f32 unk250;
};

extern "C" void func_001C3958(mGTShirtPS2 *arg0);

extern "C" void func_001C2FF8(mGTShirtPS2 *arg0, f32 fparg0) {
    arg0->unk250 = fparg0;
    func_001C3958(arg0);
}
