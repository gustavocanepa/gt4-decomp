typedef float f32;

struct Obj { char pad[0x8]; f32 unk8; };

extern "C" void func_0040CEE0(Obj **arg0, f32 fparg0) {
    (*arg0)->unk8 = fparg0;
}
