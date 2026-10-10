extern "C" int func_0058DF18(int port, void *a, void *b);
extern "C" void func_00577F80(void);

extern "C" void func_00562618(void *a, void *b) {
    while (func_0058DF18(0, a, b) != 1)
        func_00577F80();
}
