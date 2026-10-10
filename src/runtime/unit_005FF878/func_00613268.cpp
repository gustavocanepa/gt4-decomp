extern "C" void func_00576100(void *mutex); /* lock */
extern "C" void func_00576140(void *mutex); /* unlock */

struct ScopedLock {
    void *mutex;
    ScopedLock(void *m) : mutex(m) { func_00576100(mutex); }
    ~ScopedLock() { func_00576140(mutex); }
};

struct Obj {
    char pad0[0x1C];
    char mutex[4];
};

extern "C" void func_0057B3B0(Obj *self, void *item);

extern "C" void func_00613268(Obj *self, void *item) {
    ScopedLock lock(self->mutex);
    if (item)
        func_0057B3B0(self, item);
}
