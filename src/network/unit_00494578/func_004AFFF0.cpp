extern char D_0084D5A0;

extern "C" void func_00576090(void *a0);
extern "C" void func_005760A8(void *a0, int a1);

extern "C" void func_004AFFF0(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_00576090(&D_0084D5A0);
        }
        if (arg0 == 0) {
            func_005760A8(&D_0084D5A0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_004AFFF0(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_004AFFF0(0, 0xFFFF);
}
