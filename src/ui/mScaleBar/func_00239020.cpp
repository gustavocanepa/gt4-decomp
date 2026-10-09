typedef float f32;

struct Obj {
    char pad[0xC4];
    f32 unkC4;
    f32 unkC8;
    f32 unkCC;
};

extern "C" void func_00239020(Obj *arg0, f32 arg1) {
    f32 v = arg1;
    if (v < arg0->unkC8) {
        v = arg0->unkC8;
    }
    if (arg0->unkCC < v) {
        v = arg0->unkCC;
    }
    arg0->unkC4 = v;
}
