typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_0067E598;

extern "C" void func_003A27B0(S *arg0) {
    register s32 v1 asm("$3") = (s32)&D_0067E598;
    arg0->unk4 = 0;
    arg0->unk0 = v1;
}
