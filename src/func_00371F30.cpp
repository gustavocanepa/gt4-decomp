typedef int s32;

struct S { char pad[0xC]; s32 unkC; };

extern "C" void func_00371F30(S *arg0, s32 arg1) {
    arg0->unkC = arg1;
}
