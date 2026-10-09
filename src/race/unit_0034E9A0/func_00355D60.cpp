typedef float f32;

struct S { char pad[0x788]; f32 unk788; };

extern "C" void func_00355D60(S *arg0, f32 arg1) {
    arg0->unk788 = arg1;
}
