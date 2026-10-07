typedef float f32;

struct Obj { char pad[0x44]; f32 unk44; };

extern "C" void func_0040CFD0(Obj **arg0, f32 fparg0) {
    (*arg0)->unk44 = fparg0;
}
