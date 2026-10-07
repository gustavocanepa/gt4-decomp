typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void *func_00147D80(void *arg0);
extern "C" s32 func_0043EC08(void *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline s32 vcall(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_0014A530(void **arg0, void *arg1, s32 n, Obj **args) {
    Handle h;
    void *o;
    func_0013BDC0(&h, arg1);
    o = func_00147D80(h.p);
    func_0013BD68(&h, 2);
    func_002FE278(&h, vcall(*args) != 0 ? -1 : func_0043EC08(o));
    if ((void *)arg0 != (void *)&h) {
        void *p = h.p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = p;
    }
    func_002FC870(&h, 2);
}
