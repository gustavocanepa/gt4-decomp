typedef float f32;

struct S { char pad[0x90]; f32 unk90; };

extern "C" void func_004519A0(S *arg0, f32 arg1) {
    arg0->unk90 = arg1;
}
