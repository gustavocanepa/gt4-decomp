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
    s32 pad[3];
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

extern char D_00698E18[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0023DDF0(void *arg0, int arg1);
extern "C" void *func_0023DE48(void *arg0);
extern "C" void func_0023FA18(s32 a0, const char *a1);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_00698E18;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" void func_0023E4B8(void *arg0, void *arg1, s32 n, Obj **args) {
    if (n > 0) {
        s32 tmp[8];
        Str s;
        Str *ps;
        s32 h;
        const char *name;
        func_0023DE48(tmp);
        {
            Obj *o = *args;
            VEntry *e;
            ps = &s;
            h = tmp[0];
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
        }
        name = c_str(ps);
        {
            Rep *q = (Rep *)(*(s32 *)&ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_0023FA18(h, name);
        func_0023DDF0(tmp, 2);
    }
}
