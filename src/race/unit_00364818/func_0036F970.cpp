typedef float f32;

struct S { char pad[0x4]; f32 unk4; };

extern "C" void func_0036F970(S *arg0, f32 arg1) {
    arg0->unk4 = arg1;
}
