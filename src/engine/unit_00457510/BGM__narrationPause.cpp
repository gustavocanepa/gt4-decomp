typedef int s32;

extern s32 D_0084688C;

extern "C" void func_005588F0(void);

extern "C" void BGM__narrationPause(void) {
    if (D_0084688C != 0) {
        func_005588F0();
    }
}
