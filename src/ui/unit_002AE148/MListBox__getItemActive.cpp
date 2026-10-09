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

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_002AE968(void *arg0, int arg1);
extern "C" void func_002AE9C0(void *arg0, void *arg1);
extern "C" s32 func_002B5498(void *a, s32 b);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, bool arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline s32 vcall(VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void MListBox__getItemActive(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    if (arg2 == 1) {
        Handle o;
        Handle h;
        Handle *ph;
        void *op;
        bool b;
        func_002AE9C0(&o, arg1);
        op = o.p;
        b = func_002B5498(op, vcall(*arg3)) != 0;
        ph = &h;
        func_002FE278(ph, b);
        if ((void *)arg0 != (void *)ph) {
            void *p = ph->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(ph, 2);
        func_002AE968(&o, 2);
    }
}
