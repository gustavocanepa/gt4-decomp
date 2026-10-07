typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_0067FB18;

extern "C" void func_005FAB30(S *arg0) {
    register s32 v1 asm("$3") = (s32)&D_0067FB18;
    arg0->unk4 = 0;
    arg0->unk0 = v1;
}
