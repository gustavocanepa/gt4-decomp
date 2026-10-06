extern char D_006D67B0;

extern "C" void func_00576090(void *a0);
extern "C" void func_005760A8(void *a0, int a1);

extern "C" void func_00558B30(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_00576090(&D_006D67B0);
        }
        if (arg0 == 0) {
            func_005760A8(&D_006D67B0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_00558B30(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_00558B30(0, 0xFFFF);
}
