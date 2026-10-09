typedef int s32;

struct Obj {
    char pad0[4];
};

extern "C" void func_001B9088(void *arg0, int arg1);
extern "C" void *func_001B90E0(void *arg0, void *arg1);
extern "C" void func_00309378(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

struct Handle {
    void *p;
    char pad[0xC];
    ~Handle() { func_00309378(this, 2); }
    Handle &operator=(const Handle &o) {
        if (this != &o) {
            void *q = o.p;
            if (q != 0) {
                func_003285A8(q);
            }
            if (p != 0) {
                func_003285F8(p);
            }
            p = q;
        }
        return *this;
    }
};

struct Holder {
    Obj *p;
    char pad[0xC];
    Holder(void *a) { func_001B90E0(this, a); }
    ~Holder() { func_001B9088(this, 2); }
    Obj *get() { return p; }
};

typedef Handle (Obj::*PM)(void);

extern "C" void func_005CF380(Handle *arg0, void *arg1, s32 arg2, s32 arg3, PM pmf) {
    *arg0 = (Holder(arg1).get()->*pmf)();
}
