typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_006829B8;

extern "C" void func_005FDC00(S *arg0) {
    register s32 v1 asm("$3") = (s32)&D_006829B8;
    arg0->unk4 = 0;
    arg0->unk0 = v1;
}
