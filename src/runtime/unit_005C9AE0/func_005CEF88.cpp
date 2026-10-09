typedef int s32;

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(int);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_001B8248(void *arg0, int arg1);
extern "C" void func_001B82A0(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" int func_00314920(void *arg0);

static inline Obj *hget(Handle *h) { return h->p; }

static inline int chk(Handle *ph, void *a3) {
    func_00312370(ph, a3);
    return func_00314920(ph->p);
}

extern "C" void func_005CEF88(void *arg0, void *arg1, s32 arg2, void *arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle h;
        Handle *po = &o;
        Handle *ph;
        func_001B82A0(po, arg1);
        ph = &h;
        (hget(po)->*pmf)(chk(ph, arg3));
        func_00312318(ph, 2);
        func_001B8248(po, 2);
    }
}
