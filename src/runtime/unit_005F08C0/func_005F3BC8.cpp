typedef float f32;

struct Obj {
    char pad0[0xCF50];
    f32 unkCF50;
};

extern "C" void func_005F3BC8(Obj *arg0, f32 fparg0) {
    arg0->unkCF50 = 1.0f / fparg0;
}
