typedef float f32;

struct S_00200EC0 { char pad[0xB4]; f32 unkB4; };

extern "C" void func_00200EC0(S_00200EC0 *arg0, f32 arg1) {
    arg0->unkB4 = arg1;
}
