extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" void func_00574EE8(void *p);

struct LockGuard {
    void *lock;
    LockGuard(void *l) : lock(l) { func_00576100(l); }
    ~LockGuard() { func_00576140(lock); }
};

struct State {
    char pad0[0x39];
    unsigned char dirty;
};

extern "C" char D_0086C8D8[];
extern "C" State D_0086C8E0;

extern "C" void func_00547B58(void) {
    State *s = &D_0086C8E0;
    {
        LockGuard guard(D_0086C8D8);
        s->dirty = 1;
    }
    func_00574EE8(s);
}
