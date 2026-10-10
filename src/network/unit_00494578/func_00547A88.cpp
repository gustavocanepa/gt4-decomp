/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Mutex { int w[2]; };
struct State { int event[12]; char a, b, c, d, e, f, g, h, i; char pad39[0x144 - 0x39]; f32 value[3]; };
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

extern "C" void func_00547A88(f32 value)
{
    {
        ScopedLock lock(&D_0086C8D8);
        D_0086C8E0.a = 1;
        D_0086C8E0.h = 1;
        D_0086C8E0.value[1] = value;
    }
    func_00574EE8(D_0086C8E0.event);
}
