typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0x1C];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(Str *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern char D_006959D8[];
extern char D_006959E0[];

extern "C" void func_001DD7B0(void *arg0);
extern "C" void func_0023B478(void *arg0);
extern "C" void func_0023CA78(void *arg0, const char *arg1, const char *arg2);
extern "C" void func_0023B1D8(void *arg0, int arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

extern "C" void MNetwork__showLanguage(void **arg0) {
    Handle h;
    Str s;
    Str *ps;
    func_001DD7B0(arg0);
    func_0023B478(&h);
    {
        Obj *o = *(Obj **)arg0;
        void *hp;
        VEntry *e;
        ps = &s;
        hp = h.p;
        e = (VEntry *)(o->vtbl + 0x18);
        e->fn(ps, (char *)o + e->delta);
        func_0023CA78(hp, c_str(ps), D_006959E0);
    }
    str_release(ps);
    func_0023B1D8(&h, 2);
    func_002FE278(&h, 1);
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
