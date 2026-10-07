typedef float f32;

struct Obj { char pad[0x14]; f32 unk14; };

extern "C" void func_0040CF10(Obj **arg0, f32 fparg0) {
    (*arg0)->unk14 = fparg0;
}
