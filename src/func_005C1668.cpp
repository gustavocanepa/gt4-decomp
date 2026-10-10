typedef void (*Handler)(void);
typedef void (*NoReturnHandler)(void) __attribute__((noreturn));

extern Handler D_0065996C;

/* terminate(): calls the installed handler, which never returns. */
extern "C" void func_005C1668(void) __attribute__((noreturn));
extern "C" void func_005C1668(void) {
    ((NoReturnHandler)D_0065996C)();
}

/* A wrapper that never returns either (glued after it in the inventory). */
extern "C" void func_005C1680(void) __attribute__((noreturn));
extern "C" void func_005C1680(void) {
    func_005C1668();
}

/* set_terminate(): installs a new handler and returns the old one. */
extern "C" Handler func_005C1690(Handler h) {
    Handler *p = &D_0065996C;
    Handler old = *p;
    *p = h;
    return old;
}
