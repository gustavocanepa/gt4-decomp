typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct VEntry {
    short delta;
    short index;
    void *(*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" s32 func_0044A218(void *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline void *vcall(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void assign(void **dst, Handle *ph) {
    if ((void *)dst != (void *)ph) {
        void *p = ph->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*dst != 0) {
            func_003285F8(*dst);
        }
        *dst = p;
    }
}

extern "C" void MCarGarage__isReversibilityType(void **arg0, void *arg1, s32 n, Obj **args) {
    if (n > 0) {
        Handle h0;
        Handle h;
        func_0013BDC0(&h0, arg1);
        {
            s32 v = func_0044A218(vcall(*args));
            Handle *ph = &h;
            func_002FE278(ph, v != 0);
            assign(arg0, ph);
            func_002FC870(ph, 2);
        }
        func_0013BD68(&h0, 2);
    }
}
