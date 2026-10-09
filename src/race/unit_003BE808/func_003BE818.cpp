typedef float f32;

struct Obj {
    char pad[0x40];
    f32 unk40;
    f32 unk44;
};

extern "C" void func_003BE818(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk44 = fparg0;
    arg0->unk40 = fparg0 * fparg1;
}
