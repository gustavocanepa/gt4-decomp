typedef int s32;

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(float);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_001BB248(void *arg0, int arg1);
extern "C" void func_001BB2A0(void *arg0, void *arg1);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F7BC0(void *arg0, void *arg1);
extern "C" float func_002F9158(void *arg0);

static inline Obj *hget(Handle *h) { return h->p; }

static inline float chk(Handle *ph, void *a3) {
    func_002F7BC0(ph, a3);
    return func_002F9158(ph->p);
}

extern "C" void func_005CFEC0(void *arg0, void *arg1, s32 arg2, void *arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle h;
        Handle *po = &o;
        Handle *ph;
        func_001BB2A0(po, arg1);
        ph = &h;
        (hget(po)->*pmf)(chk(ph, arg3));
        func_002F7B68(ph, 2);
        func_001BB248(po, 2);
    }
}
