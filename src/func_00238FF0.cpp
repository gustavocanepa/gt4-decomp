typedef float f32;

struct Obj {
    char pad[0xC8];
    f32 unkC8;
    f32 unkCC;
    char pad2[0xE8 - 0xD0];
    f32 unkE8;
};

extern "C" void func_00238FF0(Obj *arg0, f32 fparg0) {
    f32 v = fparg0;
    if (v < arg0->unkC8) {
        v = arg0->unkC8;
    }
    if (arg0->unkCC < v) {
        v = arg0->unkCC;
    }
    arg0->unkE8 = v;
}
