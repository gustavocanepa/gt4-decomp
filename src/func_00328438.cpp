typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_00676958;

extern "C" void func_00328438(S *arg0) {
    register s32 v1 asm("$3") = (s32)&D_00676958;
    arg0->unk0 = 0;
    arg0->unk4 = v1;
}
