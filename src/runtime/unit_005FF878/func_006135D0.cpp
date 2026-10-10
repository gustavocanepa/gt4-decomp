/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mutex { int w[2]; };

extern "C" void func_00576788(Mutex *m);
extern "C" void func_005767C0(Mutex *m);

struct ScopedLock {
    Mutex *m;
    ScopedLock(Mutex *mutex) : m(mutex) { func_00576788(m); }
    ~ScopedLock() { func_005767C0(m); }
};

struct Range {
    int first;
    int second;
};

struct Obj {
    char pad[0x1C];
    Mutex mutex;
};

extern "C" void func_0057B348(Obj *o, int first, int flag, int second);

extern "C" void func_006135D0(Obj *o, const Range *r) {
    int first = r->first;
    int second = r->second;
    ScopedLock lock(&o->mutex);
    func_0057B348(o, first, 1, second);
}
