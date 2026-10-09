typedef float f32;

struct Obj { char pad[0x34]; f32 unk34; };

extern "C" void func_0040CF90(Obj **arg0, f32 fparg0) {
    (*arg0)->unk34 = fparg0;
}
