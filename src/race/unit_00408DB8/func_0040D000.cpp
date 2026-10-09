typedef float f32;

struct Obj { char pad[0x50]; f32 unk50; };

extern "C" void func_0040D000(Obj **arg0, f32 fparg0) {
    (*arg0)->unk50 = fparg0;
}
