extern char D_006D67B0;

extern "C" void func_004AEC68(void *a0);
extern "C" void func_004AECA0(void *a0, int a1);

extern "C" void func_0044CE20(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004AEC68(&D_006D67B0);
        }
        if (arg0 == 0) {
            func_004AECA0(&D_006D67B0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_0044CE20(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_0044CE20(0, 0xFFFF);
}
