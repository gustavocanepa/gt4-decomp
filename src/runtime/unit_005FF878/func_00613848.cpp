extern "C" void func_00576788(void *mutex);
extern "C" void func_005767C0(void *mutex);

struct Lock {
    void *m;
    Lock(void *mutex) : m(mutex) { func_00576788(m); }
    ~Lock() { func_005767C0(m); }
};

struct Stream {
    char pad0[0x1C];
    char mutex[4];
};

extern "C" int func_0057B440(Stream *s, void *a, int b);

extern "C" int func_00613848(Stream *s, void *a, int b)
{
    Lock lock(s->mutex);
    return func_0057B440(s, a, b);
}
