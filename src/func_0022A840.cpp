typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_00667030;

extern "C" void func_0022A840(S *arg0, s32 arg1) {
    register s32 v1 asm("$3") = (s32)&D_00667030;
    arg0->unk4 = arg1;
    arg0->unk0 = v1;
}
