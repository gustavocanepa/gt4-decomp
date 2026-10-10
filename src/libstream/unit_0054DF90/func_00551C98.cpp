inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Manager {
    Manager() __asm__("func_00610A98");
};

extern Manager *D_0064C878;
extern char D_0086FD80[];

extern "C" void func_0057CB00(Manager *m, void *arg);

static inline Manager *instance() {
    if (D_0064C878 == 0)
        D_0064C878 = new (D_0086FD80) Manager;
    return D_0064C878;
}

extern "C" void func_00551C98(void *arg) {
    func_0057CB00(instance(), arg);
}
