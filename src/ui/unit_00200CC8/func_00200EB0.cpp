typedef float f32;

struct S_00200EB0 { char pad[0xB0]; f32 unkB0; };

extern "C" void func_00200EB0(S_00200EB0 *arg0, f32 arg1) {
    arg0->unkB0 = arg1;
}
