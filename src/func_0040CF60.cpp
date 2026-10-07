typedef float f32;

struct Obj { char pad[0x28]; f32 unk28; };

extern "C" void func_0040CF60(Obj **arg0, f32 fparg0) {
    (*arg0)->unk28 = fparg0;
}
