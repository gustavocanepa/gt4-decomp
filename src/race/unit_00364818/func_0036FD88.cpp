typedef float f32;

struct Obj {
    char pad[0xD0];
    f32 unkD0;
    f32 unkD4;
};

extern "C" void func_0036FD88(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unkD0 = fparg0;
    arg0->unkD4 = fparg1;
}
