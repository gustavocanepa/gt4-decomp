typedef float f32;

struct Obj { char pad[0x60]; f32 unk60; };

extern "C" void func_0040D048(Obj **arg0, f32 fparg0) {
    (*arg0)->unk60 = fparg0;
}
