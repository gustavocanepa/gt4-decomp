struct Mutex { int w[2]; };
struct State { int event[12]; char a, b, c, d, e, f; };
extern "C" Mutex D_0086C8D8;
extern "C" State D_0086C8E0;
extern "C" void func_00576100(Mutex *m);
extern "C" void func_00576140(Mutex *m);
extern "C" void func_00574EE8(void *event);

struct ScopedLock {
    Mutex *m;
    ScopedLock(Mutex *mutex) : m(mutex) { func_00576100(m); }
    ~ScopedLock() { func_00576140(m); }
};

extern "C" void func_00547960(void)
{
    {
        ScopedLock lock(&D_0086C8D8);
        D_0086C8E0.a = 1;
        D_0086C8E0.e = 1;
        D_0086C8E0.b = 0;
        D_0086C8E0.d = 0;
        D_0086C8E0.f = 0;
    }
    func_00574EE8(D_0086C8E0.event);
}
