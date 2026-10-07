typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_0068A288;

extern "C" void func_006165D8(S *arg0, s32 arg1) {
    register s32 v1 asm("$3") = (s32)&D_0068A288;
    arg0->unk0 = arg1;
    arg0->unk4 = v1;
}
