typedef float f32;

struct Obj { char pad[0x1C]; f32 unk1C; };

extern "C" void func_0040CF30(Obj **arg0, f32 fparg0) {
    (*arg0)->unk1C = fparg0;
}
