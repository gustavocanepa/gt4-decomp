typedef int s32;

struct S { char pad[0x490]; s32 unk490; };

extern "C" void func_0043E2E8(S *arg0, s32 arg1) {
    arg0->unk490 = arg1;
}
