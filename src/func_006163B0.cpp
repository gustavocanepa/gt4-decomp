typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_0068A2F8;

extern "C" void func_006163B0(S *arg0, s32 arg1) {
    register s32 v1 asm("$3") = (s32)&D_0068A2F8;
    arg0->unk0 = arg1;
    arg0->unk4 = v1;
}
