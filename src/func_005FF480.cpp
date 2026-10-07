typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_00686328;

extern "C" void func_005FF480(S *arg0) {
    register s32 v1 asm("$3") = (s32)&D_00686328;
    arg0->unk4 = 0;
    arg0->unk0 = v1;
}
