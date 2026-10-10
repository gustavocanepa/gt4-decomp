/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mutex { int w[2]; };

extern "C" void func_00576100(Mutex *m);
extern "C" void func_00576140(Mutex *m);

struct ScopedLock {
    Mutex *m;
    ScopedLock(Mutex *mutex) : m(mutex) { func_00576100(m); }
    ~ScopedLock() { func_00576140(m); }
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

extern "C" void func_00613178(Obj *o, const Range *r) {
    int first = r->first;
    int second = r->second;
    ScopedLock lock(&o->mutex);
    func_0057B348(o, first, 1, second);
}
