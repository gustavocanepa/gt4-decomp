extern signed char D_0062A038;

extern "C" unsigned char func_004AA308(void);

extern "C" void func_004AA350(unsigned char *buf, int n) {
    if (D_0062A038)
        return;
    for (int i = 0; i < n; i++)
        *buf++ ^= func_004AA308();
    D_0062A038 = 1;
}
