typedef float f32;

struct Obj { char pad[0x24]; f32 unk24; };

extern "C" void func_0040CF50(Obj **arg0, f32 fparg0) {
    (*arg0)->unk24 = fparg0;
}
