typedef float f32;

struct Obj { char pad[0x48]; f32 unk48; };

extern "C" void func_0040CFE0(Obj **arg0, f32 fparg0) {
    (*arg0)->unk48 = fparg0;
}
