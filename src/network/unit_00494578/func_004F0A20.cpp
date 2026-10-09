extern "C" void func_005A5A30(int arg0, int arg1, const char *fmt, void *buf, int val);
extern "C" void func_005A609C(void *arg0, int arg1);


extern "C" void func_004F0A20(void *arg0, int arg1) {
    char *base = (char *)arg0;

    if (arg1 != 0) {
        int *p399C = (int *)(base + 0x399C);
        int old = (*p399C)++;
        func_005A5A30(arg1, 0x15, "%s%x", base + 0xAF8, old);
        func_005A609C(base + 0x3984, arg1);
    }
    *(int *)(base + 0x39A0) = 1;
}
