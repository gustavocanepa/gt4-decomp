typedef float f32;

struct Obj { char pad[0x40]; f32 unk40; };

extern "C" void func_0040CFC0(Obj **arg0, f32 fparg0) {
    (*arg0)->unk40 = fparg0;
}
