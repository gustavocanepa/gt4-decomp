extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_0057B368(void *);

/* Scoped lock: locks in the constructor, unlocks in the destructor. */
struct Lock {
    void *m;
    Lock(void *mutex) : m(mutex) { func_00576788(m); }
    ~Lock() { func_005767C0(m); }
};

struct Obj {
    char pad[0x1C];
    char mutex[4];
};

extern "C" void func_00613638(Obj *self) {
    Lock lock(self->mutex);
    func_0057B368(self);
}
