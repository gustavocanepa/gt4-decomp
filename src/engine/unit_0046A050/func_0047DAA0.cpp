typedef float f32;

struct S { char pad[0x40]; f32 unk40; };

extern "C" void func_0047DAA0(S *arg0, f32 arg1) {
    arg0->unk40 = arg1;
}
