extern char D_0064C880;

extern "C" void func_00574D78(void *a0);
extern "C" void func_00574DA8(void *a0, int a1);

extern "C" void func_00552550(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_00574D78(&D_0064C880);
        }
        if (arg0 == 0) {
            func_00574DA8(&D_0064C880, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_00552550(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_00552550(0, 0xFFFF);
}
