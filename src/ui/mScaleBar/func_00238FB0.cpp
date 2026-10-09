typedef float f32;

struct S { char pad[0xD8]; f32 unkD8; };

extern "C" void func_00238FB0(S *arg0, f32 arg1) {
    arg0->unkD8 = arg1;
}
