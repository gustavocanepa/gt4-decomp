typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
};

extern char D_00688628;

extern "C" void func_00453680(S *arg0, s32 arg1) {
    register s32 v1 asm("$3") = (s32)&D_00688628;
    arg0->unk4 = arg1;
    arg0->unk0 = v1;
}
