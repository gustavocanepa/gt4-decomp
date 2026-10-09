typedef int s32;
typedef short s16;

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

struct Inner {
    char pad[0x10];
    s32 p10;
};

struct Handle {
    Inner *p;
    char pad[0xC];
};

struct VEntry {
    s16 delta;
    s16 index;
    Str (*fn)(void *);
};

struct VObj {
    char pad[4];
    VEntry *vtbl;
};

extern Rep D_00659FA8;
extern char D_006915D0[];

static inline Inner *get(Handle *h) {
    return h->p;
}

extern "C" void func_0017FAD0(void *arg0, int arg1);
extern "C" void *func_0017FB28(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" const char *func_004368D0(s32 arg0);
extern "C" void func_004368F8(s32 arg0, const char *arg1);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MOption__get_unit_torque(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Handle buf;
    if (arg2 > 0) {
        func_0017FB28(&buf, arg1);
        {
            Inner *op = buf.p;
            VObj *o = *arg3;
            VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
            const char *c;
            s32 len;
            Str t = e->fn((char *)o + e->delta);
            Str *pt = &t;
            len = *(s32 *)(pt->p - 0x10);
            if (len == 0) {
                c = D_006915D0;
            } else {
                pt->p[len] = 0;
                c = pt->p;
            }
            func_004368F8(op->p10, c);
            str_release(pt);
        }
        func_0017FAD0(&buf, 2);
    } else {
        Handle h;
        Str s;
        Str *ps;
        s32 newVal;
        s32 oldVal;
        const char *src;
        func_0017FB28(&buf, arg1);
        ps = &s;
        src = func_004368D0(get(&buf)->p10);
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        {
            Handle *ph = &h;
            func_00314B20(ph, ps);
            if ((void *)arg0 != (void *)ph) {
                newVal = (s32)ph->p;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *arg0;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *arg0 = newVal;
            }
            func_00312318(ph, 2);
        }
        str_release(ps);
        func_0017FAD0(&buf, 2);
    }
}
