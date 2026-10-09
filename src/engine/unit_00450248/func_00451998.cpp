typedef int s32;

struct S { char pad[0x8C]; s32 unk8C; };

extern "C" void func_00451998(S *arg0, s32 arg1) {
    arg0->unk8C = arg1;
}
