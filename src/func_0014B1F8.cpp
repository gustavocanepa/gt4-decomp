typedef int s32;

struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct VObj {
    int pad;
    VEntry *vtbl;
};

static inline int vcall11(VObj *o) {
    VEntry *e = &o->vtbl[11];
    return e->fn((char *)o + e->delta);
}

struct Handle {
    void *p;
    int pad[3];
};

extern "C" {
void func_0013BDC0(Handle *h);
void func_0013BD68(Handle *h, int flags);
void *func_00147D80(void *p);
int func_0043F090(void *ctx);
int func_0043F0B8(void *ctx);
int func_0043F0E0(void *ctx);
int func_0043F108(void *ctx);
int func_0043F130(void *ctx);
int func_0043F158(void *ctx);
void func_002FE278(void *, s32);
void func_003285A8(s32);
void func_003285F8(s32);
void func_002FC870(void *, s32);
}

extern "C" void func_0014B1F8(s32 *ret, int a1, int a2, VObj **args) {
    union {
        Handle h;
        s32 buf[4];
    } t;
    func_0013BDC0(&t.h);
    void *ctx = func_00147D80(t.h.p);
    func_0013BD68(&t.h, 2);
    int r;
    switch (vcall11(args[0])) {
    case 0:
        r = func_0043F090(ctx);
        break;
    case 1:
        r = func_0043F0B8(ctx);
        break;
    case 2:
        r = func_0043F0E0(ctx);
        break;
    case 3:
        r = func_0043F108(ctx);
        break;
    case 4:
        r = func_0043F130(ctx);
        break;
    case 5:
        r = func_0043F158(ctx);
        break;
    default:
        r = -1;
        break;
    }
    func_002FE278(t.buf, r);
    if (ret != t.buf) {
        s32 newVal = t.buf[0];
        if (newVal != 0)
            func_003285A8(newVal);
        s32 oldVal = *ret;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *ret = newVal;
    }
    func_002FC870(t.buf, 2);
}
