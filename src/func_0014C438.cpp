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
int func_0043EDC0(void *ctx);
int func_0043EDE8(void *ctx);
int func_0043EE10(void *ctx);
int func_0043EE38(void *ctx);
int func_0043EE60(void *ctx);
int func_0043EE88(void *ctx);
int func_0043EEB0(void *ctx);
int func_0043EED8(void *ctx);
int func_0043EF00(void *ctx);
int func_0043EF28(void *ctx);
int func_0043EF50(void *ctx);
int func_0043EF78(void *ctx);
int func_0043EFA0(void *ctx);
int func_0043EFC8(void *ctx);
int func_0043EFF0(void *ctx);
int func_0043F018(void *ctx);
int func_0043F040(void *ctx);
int func_0043F068(void *ctx);
void func_002FE278(void *, s32);
void func_003285A8(s32);
void func_003285F8(s32);
void func_002FC870(void *, s32);
}

extern "C" void func_0014C438(s32 *ret, int a1, int a2, VObj **args) {
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
        r = func_0043EDC0(ctx);
        break;
    case 1:
        r = func_0043EDE8(ctx);
        break;
    case 2:
        r = func_0043EE10(ctx);
        break;
    case 3:
        r = func_0043EE38(ctx);
        break;
    case 4:
        r = func_0043EE60(ctx);
        break;
    case 5:
        r = func_0043EE88(ctx);
        break;
    case 6:
        r = func_0043EEB0(ctx);
        break;
    case 7:
        r = func_0043EED8(ctx);
        break;
    case 8:
        r = func_0043EF00(ctx);
        break;
    case 9:
        r = func_0043EF28(ctx);
        break;
    case 10:
        r = func_0043EF50(ctx);
        break;
    case 11:
        r = func_0043EF78(ctx);
        break;
    case 12:
        r = func_0043EFA0(ctx);
        break;
    case 13:
        r = func_0043EFC8(ctx);
        break;
    case 14:
        r = func_0043EFF0(ctx);
        break;
    case 15:
        r = func_0043F018(ctx);
        break;
    case 16:
        r = func_0043F040(ctx);
        break;
    case 17:
        r = func_0043F068(ctx);
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
