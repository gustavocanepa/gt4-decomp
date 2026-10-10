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
    void (*fn)(void *, Str *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);extern char D_0083F6A0[];
extern "C" void func_00305550(Obj *arg0, void *arg1);

extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int hObject__GetClassID(void);
extern "C" void func_002F3A30(Obj *arg0, s32 arg1);
extern "C" void func_002F36E0(Obj *arg0, void *arg1, void (*arg2)(void));
extern "C" void func_002F3818(Obj *arg0, Str *arg1, void (*arg2)(void));
extern "C" void func_002F3860(Obj *arg0, Str *arg1, void (*arg2)(void), void (*arg3)(void));
extern "C" void func_00306780(Obj *arg0, void *arg1, void (*arg2)(void));
extern char D_0069DDC8[];
extern char D_0069DDD8[];
extern char D_0069DDE0[];
extern char D_0069DDE8[];
extern char D_0069DDF8[];
extern char D_0069DE00[];
extern char D_0069DE10[];
extern char D_0069DE20[];
extern char D_0069DE30[];
extern char D_0069DE38[];
extern char D_0083F6E0[];
extern char D_0083F758[];
extern char D_0083F710[];
extern char D_0083F608[];
extern char D_0083F5E0[];
extern char D_0083F638[];
extern char D_0083F658[];
extern char D_0083F668[];
extern char D_0083F660[];
extern char D_0083F800[];
extern char D_0083F650[];
extern char D_0083F648[];
extern char D_0083F640[];
extern char D_0083F5D8[];
extern char D_0083F5F8[];
extern char D_0083F5D0[];
extern char HSymbol__OP_MOD[];
extern char D_0083F7F8[];
extern char HSymbol__OP_NOT[];
extern char D_0083F7F0[];
extern char D_0083F680[];
extern char D_0083F678[];
extern char D_0083F600[];
extern char D_0083F628[];
extern char D_0083F610[];
extern char D_0083F670[];
extern char D_0083F620[];
extern char D_0083F630[];
extern char D_0083F618[];
extern char D_0083F6B8[];
extern "C" void adhoc__global_0083F6E0(void);
extern "C" void adhoc__global_0083F758(void);
extern "C" void adhoc__toString(void);
extern "C" void adhoc__toFloat(void);
extern "C" void adhoc__toInt(void);
extern "C" void adhoc__get_class_id(void);
extern "C" void adhoc__get_rc_size(void);
extern "C" void adhoc__get_rc_class(void);
extern "C" void adhoc__get_rc_count(void);
extern "C" void adhoc__get_weak_count(void);
extern "C" void adhoc__dump(void);
extern "C" void adhoc__getDeepCopy(void);
extern "C" void adhoc__global_0083F710(void);
extern "C" void adhoc__global_0083F658(void);
extern "C" void adhoc__global_0083F5D0(void);

extern "C" void hObject__InitClass(Obj *arg0) {
    Str s;
    func_00305550(arg0, D_0083F6A0);
    func_002F3A30(arg0, 0);
    func_00306780(arg0, D_0083F6E0, adhoc__global_0083F6E0);
    func_002F36E0(arg0, D_0083F758, adhoc__global_0083F758);
    {
        Str *ps = &s;
        const char *src = D_0069DDC8;
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
        func_002F3818(arg0, &s, adhoc__toString);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DDD8;
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
        func_002F3818(arg0, &s, adhoc__toFloat);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DDE0;
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
        func_002F3818(arg0, &s, adhoc__toInt);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DDE8;
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
        func_002F3860(arg0, &s, adhoc__get_class_id, 0);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DDF8;
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
        func_002F3860(arg0, &s, adhoc__get_rc_size, 0);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DE00;
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
        func_002F3860(arg0, &s, adhoc__get_rc_class, 0);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DE10;
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
        func_002F3860(arg0, &s, adhoc__get_rc_count, 0);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DE20;
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
        func_002F3860(arg0, &s, adhoc__get_weak_count, 0);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DE30;
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
        func_002F3818(arg0, &s, adhoc__dump);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_0069DE38;
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
        func_002F3818(arg0, &s, adhoc__getDeepCopy);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F36E0(arg0, D_0083F710, adhoc__global_0083F710);
    func_002F36E0(arg0, D_0083F608, 0);
    func_002F36E0(arg0, D_0083F5E0, 0);
    func_002F36E0(arg0, D_0083F638, 0);
    func_002F36E0(arg0, D_0083F658, adhoc__global_0083F658);
    func_002F36E0(arg0, D_0083F668, 0);
    func_002F36E0(arg0, D_0083F660, 0);
    func_002F36E0(arg0, D_0083F800, 0);
    func_002F36E0(arg0, D_0083F650, 0);
    func_002F36E0(arg0, D_0083F648, 0);
    func_002F36E0(arg0, D_0083F640, 0);
    func_002F36E0(arg0, D_0083F5D8, 0);
    func_002F36E0(arg0, D_0083F5F8, 0);
    func_002F36E0(arg0, D_0083F5D0, adhoc__global_0083F5D0);
    func_002F36E0(arg0, HSymbol__OP_MOD, 0);
    func_002F36E0(arg0, D_0083F7F8, 0);
    func_002F36E0(arg0, HSymbol__OP_NOT, 0);
    func_002F36E0(arg0, D_0083F7F0, 0);
    func_002F36E0(arg0, D_0083F680, 0);
    func_002F36E0(arg0, D_0083F678, 0);
    func_002F36E0(arg0, D_0083F600, 0);
    func_002F36E0(arg0, D_0083F628, 0);
    func_002F36E0(arg0, D_0083F610, 0);
    func_002F36E0(arg0, D_0083F670, 0);
    func_002F36E0(arg0, D_0083F620, 0);
    func_002F36E0(arg0, D_0083F630, 0);
    func_002F36E0(arg0, D_0083F618, 0);
    func_002F36E0(arg0, D_0083F6B8, 0);
}
