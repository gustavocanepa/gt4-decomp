typedef float f32;

struct S003BE828 {
    char pad0[0x48];
    f32 unk48;
    f32 unk4C;
};

extern "C" void func_003BE828(S003BE828 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk48 = fparg0 + 90.0f;
    arg0->unk4C = fparg1 + 90.0f;
}
