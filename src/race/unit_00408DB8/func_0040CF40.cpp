typedef float f32;

struct Obj {
    char pad[0x20];
    f32 unk20;
};

extern "C" void func_0040CF40(Obj **arg0, f32 fparg0) {
    (*arg0)->unk20 = fparg0;
}
