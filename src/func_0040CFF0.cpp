typedef float f32;

struct Obj { char pad[0x4C]; f32 unk4C; };

extern "C" void func_0040CFF0(Obj **arg0, f32 fparg0) {
    (*arg0)->unk4C = fparg0;
}
