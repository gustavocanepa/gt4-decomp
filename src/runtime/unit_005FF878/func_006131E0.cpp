extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0057B368(void *);

/* Scoped lock: locks in the constructor, unlocks in the destructor. */
struct Lock {
    void *m;
    Lock(void *mutex) : m(mutex) { func_00576100(m); }
    ~Lock() { func_00576140(m); }
};

struct Obj {
    char pad[0x1C];
    char mutex[4];
};

extern "C" void func_006131E0(Obj *self) {
    Lock lock(self->mutex);
    func_0057B368(self);
}
