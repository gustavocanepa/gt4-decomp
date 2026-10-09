typedef float f32;

struct Obj { char pad[0x2C]; f32 unk2C; };

extern "C" void func_0040CF70(Obj **arg0, f32 fparg0) {
    (*arg0)->unk2C = fparg0;
}
