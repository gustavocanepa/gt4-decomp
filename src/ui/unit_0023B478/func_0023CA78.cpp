extern "C" void func_00227BE0(void *out, const char *s);
extern "C" const char D_00698D60[];

struct Obj {
    char pad0[0x10];
    void *out;
};

extern "C" void func_0023CA78(Obj *o, const char *a, const char *b) {
    void **p = &o->out;
    if (*p) {
        if (b)
            func_00227BE0(*p, b);
        func_00227BE0(*p, a);
        return func_00227BE0(*p, D_00698D60);
    }
}
