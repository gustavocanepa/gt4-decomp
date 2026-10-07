typedef float f32;

struct S { char pad[0x34]; f32 unk34; };

extern "C" void func_0047DBB0(S *arg0, f32 arg1) {
    arg0->unk34 = arg1;
}
