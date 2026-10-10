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
void func_0043E598(void *ctx, int);
void func_0043E5C0(void *ctx, int);
void func_0043E630(void *ctx, int);
void func_0043E658(void *ctx, int);
void func_0043E6C8(void *ctx, int);
void func_0043E6F0(void *ctx, int);
void func_0043E760(void *ctx, int);
void func_0043E788(void *ctx, int);
void func_0043E7B0(void *ctx, int);
void func_0043E7D8(void *ctx, int);
void func_0043E800(void *ctx, int);
void func_0043E828(void *ctx, int);
void func_0043E850(void *ctx, int);
void func_0043E878(void *ctx, int);
void func_0043E8A0(void *ctx, int);
void func_0043E8C8(void *ctx, int);
void func_0043E8F0(void *ctx, int);
void func_0043E918(void *ctx, int);
}

extern "C" void func_0014C638(int a0, int a1, int a2, VObj **args) {
    Handle h;
    func_0013BDC0(&h);
    void *ctx = func_00147D80(h.p);
    func_0013BD68(&h, 2);
    int v = vcall11(args[1]);
    switch (vcall11(args[0])) {
    case 0:
        func_0043E598(ctx, v);
        break;
    case 1:
        func_0043E5C0(ctx, v);
        break;
    case 2:
        func_0043E630(ctx, v);
        break;
    case 3:
        func_0043E658(ctx, v);
        break;
    case 4:
        func_0043E6C8(ctx, v);
        break;
    case 5:
        func_0043E6F0(ctx, v);
        break;
    case 6:
        func_0043E760(ctx, v);
        break;
    case 7:
        func_0043E788(ctx, v);
        break;
    case 8:
        func_0043E7B0(ctx, v);
        break;
    case 9:
        func_0043E7D8(ctx, v);
        break;
    case 10:
        func_0043E800(ctx, v);
        break;
    case 11:
        func_0043E828(ctx, v);
        break;
    case 12:
        func_0043E850(ctx, v);
        break;
    case 13:
        func_0043E878(ctx, v);
        break;
    case 14:
        func_0043E8A0(ctx, v);
        break;
    case 15:
        func_0043E8C8(ctx, v);
        break;
    case 16:
        func_0043E8F0(ctx, v);
        break;
    case 17:
        func_0043E918(ctx, v);
        break;
    }
}
