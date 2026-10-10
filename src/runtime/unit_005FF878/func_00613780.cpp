extern "C" void func_00576788(void *mutex); /* lock */
extern "C" void func_005767C0(void *mutex); /* unlock */

struct ScopedLock {
    void *mutex;
    ScopedLock(void *m) : mutex(m) { func_00576788(mutex); }
    ~ScopedLock() { func_005767C0(mutex); }
};

struct Obj {
    char pad0[0x1C];
    char mutex[4];
};

extern "C" void func_0057B410(Obj *self, void *item);

extern "C" void func_00613780(Obj *self, void *item) {
    ScopedLock lock(self->mutex);
    if (item)
        func_0057B410(self, item);
}
