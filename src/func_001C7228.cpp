typedef int s32;

struct S {
    char pad0[0xB0];
    s32 unkB0;
};

extern "C" void func_005C1628(S *arg0);
extern char D_00660D80;

extern "C" void func_001C7228(S *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unkB0 = (s32)&D_00660D80;
    if (arg1) {
        func_005C1628(arg0);
        return;
    }
}
