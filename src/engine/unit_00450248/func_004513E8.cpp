typedef float f32;

struct S { char pad[0x60]; f32 unk60; };

extern "C" void func_004513E8(S *arg0, f32 arg1) {
    arg0->unk60 = arg1;
}
