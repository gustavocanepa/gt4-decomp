typedef float f32;

struct Obj {
    char pad0[0xC8];
    f32 unkC8;
    f32 unkCC;
    char pad1[0xE4 - 0xD0];
    f32 unkE4;
};

extern "C" void func_00238FC0(Obj *arg0, f32 fparg0) {
    f32 v = fparg0;
    f32 lo = arg0->unkC8;
    if (v < lo) {
        v = lo;
    }
    f32 hi = arg0->unkCC;
    if (hi < v) {
        v = hi;
    }
    arg0->unkE4 = v;
}
