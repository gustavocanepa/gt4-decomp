extern "C" void func_00576100(void *mutex);
extern "C" void func_00576140(void *mutex);

struct Lock {
    void *m;
    Lock(void *mutex) : m(mutex) { func_00576100(m); }
    ~Lock() { func_00576140(m); }
};

struct Stream {
    char pad0[0x1C];
    char mutex[4];
};

extern "C" int func_0057B500(Stream *s, void *a, int b);

extern "C" int func_00613460(Stream *s, void *a, int b)
{
    Lock lock(s->mutex);
    return func_0057B500(s, a, b);
}
