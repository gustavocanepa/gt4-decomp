/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
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
