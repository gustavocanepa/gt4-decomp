struct Name {
    const char *str;
    Name(const char *s) __asm__("func_002FC8C8");
    ~Name() __asm__("func_002FC870");
};

extern "C" int func_002FE250(const char *s);
extern "C" int D_00618EE8;

extern "C" void func_0021DE80(void *self, int count, const char *s) {
    int ok = 1;
    if (count > 0) {
        Name n(s);
        ok = func_002FE250(n.str) != 0;
    }
    D_00618EE8 = ok;
}
