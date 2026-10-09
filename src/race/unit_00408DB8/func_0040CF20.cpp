typedef float f32;

struct Obj { char pad[0x18]; f32 unk18; };

extern "C" void func_0040CF20(Obj **arg0, f32 fparg0) {
    (*arg0)->unk18 = fparg0;
}
