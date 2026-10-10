struct Holder {
    int (*fn)(void);
    Holder(int (*f)(void)) : fn(f) {}
};
struct Holder2 {
    void (*fn)(void);
    Holder2(void (*f)(void)) : fn(f) {}
};

extern "C" int func_00577168(void);
extern "C" void func_00577180(void);
extern "C" char D_00655878[];
extern "C" char D_00655880[];
extern "C" void func_00577170(void *self, const Holder &h, int n);
extern "C" void func_00577188(void *self, const Holder2 &h, int n);

/* Static initialisation of two callback globals; the inline constructors take a non-const self
   (a const one would load the callback's address before the object's). */
static inline void init1(void *self, int (*f)(void)) { func_00577170(self, Holder(f), 0); }
static inline void init2(void *self, void (*f)(void)) { func_00577188(self, Holder2(f), 0); }

extern "C" void func_00577BF8(int init, int prio) {
    if (prio == 0xFFFF && init == 1)
        init1(D_00655878, func_00577168);
    if (prio == 0xFFFF && init == 1)
        init2(D_00655880, func_00577180);
}
