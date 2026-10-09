typedef float f32;

struct Obj { char pad[0x58]; f32 unk58; };

extern "C" void func_0040D028(Obj **arg0, f32 fparg0) {
    (*arg0)->unk58 = fparg0;
}
