typedef int s32;

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(bool);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_001BC5F8(void *arg0, int arg1);
extern "C" void func_001BC650(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" int func_002FE250(void *arg0);

static inline Obj *hget(Handle *h) { return h->p; }

static inline bool chk(Handle *ph, void *a3) {
    func_002FC8C8(ph, a3);
    return func_002FE250(ph->p) != 0;
}

extern "C" void func_005D06A0(void *arg0, void *arg1, s32 arg2, void *arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle h;
        Handle *po = &o;
        Handle *ph;
        func_001BC650(po, arg1);
        ph = &h;
        (hget(po)->*pmf)(chk(ph, arg3));
        func_002FC870(ph, 2);
        func_001BC5F8(po, 2);
    }
}
