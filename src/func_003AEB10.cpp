extern char D_006D67B0;

extern "C" void func_00485C40(void *a0);
extern "C" void func_00485C50(void *a0, int a1);

extern "C" void func_003AEB10(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_00485C40(&D_006D67B0);
        }
        if (arg0 == 0) {
            func_00485C50(&D_006D67B0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_003AEB10(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_003AEB10(0, 0xFFFF);
}
