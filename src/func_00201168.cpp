typedef int s32;
typedef float f32;

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

struct Reader {
    union { void *vtbl; s32 word; } u;
    f32 *dst;
    char pad8[8];
};

struct Obj {
    char pad0[0xB0];
    f32 padLeft;
    f32 padRight;
    f32 padTop;
    f32 padBottom;
};

extern Rep D_00659FA8;
extern void *D_00666D20;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_00207590(Obj *self, void *node);
extern "C" s32 func_0020FD38(void *node, Str *name, Reader *r);
extern "C" void func_0020FCE0(Reader *r, s32 flags);
extern "C" void func_00200EB0(Obj *self, f32 v);
extern "C" void func_00200EC0(Obj *self, f32 v);
extern "C" void func_00200ED0(Obj *self, f32 v);
extern "C" void func_00200EE0(Obj *self, f32 v);

extern char D_006971B8[];
extern char D_006971C8[];
extern char D_006971D8[];
extern char D_006971E8[];
extern char D_006971F8[];
extern char D_00697200[];



#define STR_BUILD(SRC) \
    { \
        const char *src = SRC; \
        Rep *r = &D_00659FA8; \
        char *d; \
        if (r->sel != 0) { \
            d = func_005C2560(r); \
        } else { \
            d = (char *)(r + 1); \
            r->ref++; \
        } \
        ps->p = d; \
        func_005C2630(ps, 0, -1, src, func_0057F260(src)); \
    }

#define STR_RELEASE() \
    { \
        Rep *q = (Rep *)(ps->p - 0x10); \
        if (--q->ref == 0) { \
            s32 cap = q->cap + 0x10; \
            func_00326798(q, cap, 4, func_005C11A8()->name); \
        } \
    }

extern "C" bool func_00201168(Obj *self, void *node) {
    union { f32 f; char pad[16]; } v;
    Str s;
    Reader r3;
    Reader r1;
    s32 spare[4];
    Reader r2;
    Str *ps;
    if (func_00207590(self, node) != 0) {
        return true;
    }
    ps = &s;
    {
        s32 ok;
        Reader *pr;
        STR_BUILD(D_006971B8)
        pr = &r1;
        pr->u.vtbl = &D_00666D20;
        pr->dst = &v.f;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = &D_00666D20;
        func_0020FCE0(pr, 0);
        STR_RELEASE()
        if (ok != 0) {
            func_00200EB0(self, v.f);
            func_00200EC0(self, v.f);
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD(D_006971C8)
        pr = &r2;
        pr->u.vtbl = &D_00666D20;
        pr->dst = &v.f;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = &D_00666D20;
        func_0020FCE0(pr, 0);
        STR_RELEASE()
        if (ok != 0) {
            func_00200ED0(self, v.f);
            func_00200EE0(self, v.f);
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        f32 *dst;
        STR_BUILD(D_006971D8)
        dst = &self->padLeft;
        pr = &r3;
        pr->u.vtbl = &D_00666D20;
        pr->dst = dst;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = &D_00666D20;
        func_0020FCE0(pr, 0);
        STR_RELEASE()
        if (ok != 0) {
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        f32 *dst;
        STR_BUILD(D_006971E8)
        dst = &self->padRight;
        pr = &r3;
        pr->u.vtbl = &D_00666D20;
        pr->dst = dst;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = &D_00666D20;
        func_0020FCE0(pr, 0);
        STR_RELEASE()
        if (ok != 0) {
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        f32 *dst;
        STR_BUILD(D_006971F8)
        dst = &self->padTop;
        pr = &r3;
        pr->u.vtbl = &D_00666D20;
        pr->dst = dst;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = &D_00666D20;
        func_0020FCE0(pr, 0);
        STR_RELEASE()
        if (ok != 0) {
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        f32 *dst;
        STR_BUILD(D_00697200)
        dst = &self->padBottom;
        pr = &r3;
        pr->u.vtbl = &D_00666D20;
        pr->dst = dst;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = &D_00666D20;
        func_0020FCE0(pr, 0);
        STR_RELEASE()
        return ok;
    }
}
