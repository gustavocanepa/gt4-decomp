typedef float f32;

struct S { char pad[0x3C]; f32 unk3C; };

extern "C" void func_0047DA90(S *arg0, f32 arg1) {
    arg0->unk3C = arg1;
}
