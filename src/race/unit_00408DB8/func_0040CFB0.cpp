typedef float f32;

struct Obj { char pad[0x3C]; f32 unk3C; };

extern "C" void func_0040CFB0(Obj **arg0, f32 fparg0) {
    (*arg0)->unk3C = fparg0;
}
