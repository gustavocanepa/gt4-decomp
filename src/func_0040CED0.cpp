typedef float f32;

struct Obj { char pad[0x4]; f32 unk4; };

extern "C" void func_0040CED0(Obj **arg0, f32 fparg0) {
    (*arg0)->unk4 = fparg0;
}
