typedef float f32;

struct S { char pad[0x5C]; f32 unk5C; };

extern "C" void func_004513E0(S *arg0, f32 arg1) {
    arg0->unk5C = arg1;
}
