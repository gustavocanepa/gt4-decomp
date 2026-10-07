typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_00688350;

extern "C" void func_0044A478(S *arg0) {
    register s32 v1 asm("$3") = (s32)&D_00688350;
    arg0->unk0 = 0;
    arg0->unk4 = v1;
}
