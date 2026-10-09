typedef float f32;

struct Obj { char pad[0x54]; f32 unk54; };

extern "C" void func_0040D018(Obj **arg0, f32 fparg0) {
    (*arg0)->unk54 = fparg0;
}
