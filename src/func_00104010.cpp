typedef int s32;

extern s32 D_00618320;
extern s32 D_0061831C;

extern "C" void func_00103310(s32 arg0);

extern "C" void func_00104010(void) {
    if (D_00618320 != 0) {
        D_00618320 = 0;
        func_00103310(D_0061831C);
    }
}
