/* SGI STL (stl_alloc.h) __malloc_alloc_template<0>::_S_oom_malloc with gcc 2.96's
   __THROW_BAD_ALLOC: cerr << "out of memory" << endl; exit(1). */
typedef unsigned int size_t;

struct ostream;
extern "C" ostream &func_00592BE0(ostream &os, const char *s);
extern "C" ostream &func_00593218(ostream &os);
extern "C" void func_005A3140(int status) __attribute__((noreturn));
extern "C" void *malloc(size_t n);

struct ostream {
    char pad[1];
    ostream &operator<<(const char *s) { return func_00592BE0(*this, s); }
    ostream &operator<<(ostream &(*f)(ostream &)) { return f(*this); }
};

extern ostream cerr;
extern const char D_006AD4C0[];
extern void (*D_00617A8C)();

extern "C" void *func_00605F40(size_t n) {
    void (*handler)();
    void *result;
    for (;;) {
        handler = D_00617A8C;
        if (0 == handler) {
            cerr << D_006AD4C0 << func_00593218;
            func_005A3140(1);
        }
        (*handler)();
        result = malloc(n);
        if (result)
            return result;
    }
}
