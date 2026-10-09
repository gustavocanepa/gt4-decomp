typedef float f32;

struct Obj {
    char pad[0xCC];
    f32 unkCC;
    char pad2[0xD4 - 0xD0];
    f32 unkD4;
};

extern "C" void func_00238F98(Obj *arg0, f32 fparg0) {
    arg0->unkCC = fparg0;
    arg0->unkD4 = fparg0;
}
