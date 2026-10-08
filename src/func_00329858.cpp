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

struct Tmp {
    s32 field0;
    char pad[0xC];
};

struct Handle16 {
    void *p;
    char pad[0xC];
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" bool func_003166F8(Str *s);
extern "C" s32 func_003166B8(Str *s);
extern "C" void func_002ECDE0(Tmp *arg0);
extern "C" void func_002EA590(Tmp *arg0, s32 arg1);
extern "C" void func_002FE2E0(Handle16 *arg0);
extern "C" s32 func_002EC3A0(Handle16 *arg0, s32 arg1);
extern "C" void func_003069F8(void *obj, Handle16 *h, s32 *val);
extern "C" void func_003041B8(Handle16 *arg0, s32 arg1);
extern "C" void func_002FC870(Handle16 *arg0, s32 arg1);
extern "C" s32 func_002FE250(void *arg0);

extern "C" s32 func_00329858(s32 *arg0, const char *arg1) {
    union {
        Str s;
        Tmp tmp;
    } u;
    Handle16 h1;
    Handle16 h2;
    s32 val;
    Str s2;
    bool miss;

    {
        Str *ps = &u.s;
        const char *src = arg1;
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
        miss = !func_003166F8(&u.s);
        {
            Rep *q = (Rep *)(u.s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    if (miss) {
        return 0;
    }
    {
        Handle16 *ph1;
        Handle16 *ph2;
        void *obj;
        func_002ECDE0(&u.tmp);
        ph1 = &h1;
        func_002FE2E0(ph1);
        ph2 = &h2;
        func_002EC3A0(ph2, u.tmp.field0);
        obj = ph2->p;
        {
            Str *ps = &s2;
            s32 *pv = &val;
            const char *src = arg1;
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
            *pv = func_003166B8(ps);
            func_003069F8(obj, ph1, pv);
            {
                Rep *q = (Rep *)(ps->p - 0x10);
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }
        }
        func_003041B8(ph2, 2);
        if (ph1->p != 0) {
            *arg0 = func_002FE250(ph1->p);
            func_002FC870(ph1, 2);
            func_002EA590(&u.tmp, 2);
            return 1;
        }
        func_002FC870(ph1, 2);
        func_002EA590(&u.tmp, 2);
        return 0;
    }
}
