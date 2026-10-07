typedef float f32;

struct Obj { char pad[0x30]; f32 unk30; };

extern "C" void func_0040CF80(Obj **arg0, f32 fparg0) {
    (*arg0)->unk30 = fparg0;
}
