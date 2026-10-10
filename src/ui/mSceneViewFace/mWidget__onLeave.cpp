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

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, void *);
};

struct Obj {
    char pad0[0x9C];
    s32 flags;
};

extern Rep D_00659FA8;

extern "C" void func_0022F3A8(s32 a, void *b);
extern "C" s32 func_00265D00(Obj *arg0);
extern "C" void *func_002FA120(void *arg0);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 HSymID__GetID(Str *s);
extern "C" void func_003069F8(Obj *obj, void *h, s32 *val);
extern "C" void func_0030BB18(void *h);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" void func_005DB110(const char *fmt, const char *file, s32 line);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

struct MethodHandle {
    s32 p;
    s32 pad[3];
    MethodHandle() { func_002FA120(this); }
    ~MethodHandle() { func_002F9B38(this, 2); }
};

static inline s32 vcall10(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void vcall20(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}

#define DESTROY_ARGS()                          \
    {                                           \
        Value *q = args + 2;                    \
        while (args != q) {                     \
            --q;                                \
            func_00309378(q, 2);                \
        }                                       \
    }

extern "C" s32 mWidget__onLeave(Obj *self, s32 arg1, s32 arg2) {
    s32 newVal;
    s32 oldVal;

    if (func_00265D00(self) != 0 && (self->flags & 0x400)) {
        MethodHandle h;
        s32 ret[4];
        Str s;
        s32 *pv;
        pv = ret;
        {
            Str *ps = &s;
            const char *src = "onLeave";
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
            func_005C2630(ps, 0, -1, src, func_0057F260(src));
            *pv = HSymID__GetID(ps);
            func_003069F8(self, &h, pv);
            {
                Rep *q = (Rep *)(ps->p - 0x10);
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }
        }
        if (h.p != 0) {
            s32 r;
            func_0030BB18(pv);
            {
                Value args[2];
                s32 tmp[4];
                s32 v1;
                s32 v2;
                s32 *p0;
                Value *dst;

                p0 = tmp;
                dst = args;
                v1 = arg1;
                func_00309348(p0, &v1);
                if (dst != (Value *)p0) {
                    newVal = *p0;
                    if (newVal != 0) {
                        func_003285A8(newVal);
                    }
                    oldVal = dst->p;
                    if (oldVal != 0) {
                        func_003285F8(oldVal);
                    }
                    dst->p = newVal;
                }
                func_00309378(p0, 2);

                dst = &args[1];
                v2 = arg2;
                func_00309348(p0, &v2);
                if (dst != (Value *)p0) {
                    newVal = *p0;
                    if (newVal != 0) {
                        func_003285A8(newVal);
                    }
                    oldVal = dst->p;
                    if (oldVal != 0) {
                        func_003285F8(oldVal);
                    }
                    dst->p = newVal;
                }
                func_00309378(p0, 2);

                vcall20((VObj *)h.p, pv, 2, args);
                if (*pv != 0) {
                    r = vcall10((VObj *)*pv);
                    DESTROY_ARGS();
                    func_00309378(pv, 2);
                    return r;
                }
                func_005DB110("!!!!!!!!!!!!!!!!! you should return EventResult (%s:%d)\n", "MWidget.cpp", 0xA8E);
                DESTROY_ARGS();
                func_00309378(pv, 2);
            }
        } else {
            self->flags &= ~0x400;
        }
    }
    func_0022F3A8(arg1, 0);
    return 1;
}
