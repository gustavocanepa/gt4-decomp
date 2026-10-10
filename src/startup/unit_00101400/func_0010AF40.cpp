extern int D_00618318;
extern "C" void func_0010ACC8(int);
extern "C" void func_00578B10(int);

extern "C" void func_0010AF40(int ms) {
    if (D_00618318 != 0) {
        func_0010ACC8(D_00618318);
        if (ms != 0)
            func_00578B10(ms * 1000);
    }
}
