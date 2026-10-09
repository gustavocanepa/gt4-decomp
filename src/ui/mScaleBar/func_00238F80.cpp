typedef float f32;

struct Obj {
    char pad[0xC8];
    f32 unkC8;
    char pad2[0xD0 - 0xCC];
    f32 unkD0;
};

extern "C" void func_00238F80(volatile Obj *arg0, f32 fparg0) {
    arg0->unkD0 = fparg0;
    arg0->unkC8 = fparg0;
}
