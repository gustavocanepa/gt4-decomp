typedef float f32;

struct Obj { char pad[0xB8]; f32 unkB8; };

extern "C" void func_00200ED0(Obj *arg0, f32 arg1) {
    arg0->unkB8 = arg1;
}
