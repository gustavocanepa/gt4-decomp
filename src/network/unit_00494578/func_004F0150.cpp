extern char D_006454F0;

extern "C" void func_005720B8(void *a0);
extern "C" void func_00572148(void *a0, int a1);

extern "C" void func_004F0150(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_005720B8(&D_006454F0);
        }
        if (arg0 == 0) {
            func_00572148(&D_006454F0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_004F0150(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_004F0150(0, 0xFFFF);
}
