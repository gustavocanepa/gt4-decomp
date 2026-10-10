struct Buffers_004610E8 {
    int m0;
    char pad4[0x8];
    void *mC;
    void *m10;
};

extern "C" Buffers_004610E8 D_008468D0;
extern "C" void func_0055C338(int a, int b);
extern "C" void func_00575DA0(void *p);

extern "C" void func_004610E8(void)
{
    func_0055C338(1, 0);
    if (D_008468D0.m10) {
        func_00575DA0(D_008468D0.m10);
        D_008468D0.m10 = 0;
    }
    if (D_008468D0.mC) {
        func_00575DA0(D_008468D0.mC);
        D_008468D0.mC = 0;
    }
    D_008468D0.m0 = -1;
}
