typedef float f32;

struct Obj { char pad[0x64]; f32 unk64; };

extern "C" void func_0040D058(Obj **arg0, f32 fparg0) {
    (*arg0)->unk64 = fparg0;
}
