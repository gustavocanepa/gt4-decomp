typedef void (*Handler)(void) __attribute__((noreturn));

extern "C" Handler D_0065996C;
extern "C" int func_0057F238(const char *a, const char *b);

extern "C" void func_005BC5F0(void) {
    D_0065996C();
}

extern "C" void *func_005BC608(const char *a, const char *b, void *value) {
    void *r = value;
    if (func_0057F238(a, b) != 0) {
        r = 0;
    }
    return r;
}
