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

extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_00267DE8(s32 arg0, Str *arg1);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void func_00257B38(void *arg0, void *arg1, void *arg2, Obj **arg3) {
    Str s;
    s32 buf[4];
    {
        Obj *o = *arg3;
        VEntry *e = (VEntry *)(o->vtbl + 0x18);
        e->fn(&s, (char *)o + e->delta);
    }
    s32 *pb = buf;
    func_00255110(pb, arg1);
    func_00267DE8(*pb, &s);
    func_002550B8(pb, 2);
    {
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
}
