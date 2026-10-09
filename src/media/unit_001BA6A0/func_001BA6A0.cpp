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
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int func_00309CC0(void);
extern "C" void func_002F3A30(Obj *arg0, s32 arg1);
extern "C" int func_001B9970(void);
extern "C" void func_002F3818(Obj *arg0, Str *arg1, void (*arg2)(void));
extern "C" void func_002F3860(Obj *arg0, Str *arg1, void (*arg2)(void), void (*arg3)(void));
extern "C" void func_00306780(Obj *arg0, void *arg1, void (*arg2)(void));
extern char D_00693890[];
extern char D_006938A0[];
extern char D_006938A8[];
extern char D_006938B8[];
extern char D_006938C8[];
extern char D_006938E0[];
extern char D_006938F8[];
extern char D_00693910[];
extern char D_00693928[];
extern char D_00693938[];
extern char D_00693948[];
extern char D_00693958[];
extern char D_00693960[];
extern char D_00693970[];
extern char D_00693978[];
extern char D_00693988[];
extern char D_00827840[];
extern char D_00827838[];
extern "C" void MGTShirt__global_00827840(void);
extern "C" void MLoggerControl__global_008212E8(void);
extern "C" void MGTShirt__clear(void);
extern "C" void MGTShirt__get_threshold(void);
extern "C" void MGTShirt__set_threshold(void);
extern "C" void MGTShirt__get_threshold_cr(void);
extern "C" void MGTShirt__set_threshold_cr(void);
extern "C" void MGTShirt__get_threshold_scan_base(void);
extern "C" void MGTShirt__set_threshold_scan_base(void);
extern "C" void MGTShirt__get_threshold_scan_step(void);
extern "C" void MGTShirt__set_threshold_scan_step(void);
extern "C" void MGTShirt__get_threshold_pattern_base(void);
extern "C" void MGTShirt__set_threshold_pattern_base(void);
extern "C" void MGTShirt__get_threshold_pattern_step(void);
extern "C" void MGTShirt__set_threshold_pattern_step(void);
extern "C" void MGTShirt__set_led_start_delay(void);
extern "C" void MGTShirt__set_led_interval(void);
extern "C" void MGTShirt__set_refrect_count(void);
extern "C" void MGTShirt__set_focus(void);
extern "C" void MGTShirt__get_recognizing(void);
extern "C" void MGTShirt__set_recognizing(void);
extern "C" void MGTShirt__get_found(void);
extern "C" void MGTShirt__get_recognized(void);
extern "C" void MGTShirt__set_debug(void);

extern "C" void func_001BA6A0(Obj *arg0) {
    Str s;
    {
        Str *ps = &s;
        const char *src = D_00693890;
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
        {
            VEntry *e = (VEntry *)(arg0->vtbl + 0x190);
            e->fn((char *)arg0 + e->delta, &s);
        }
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F3A30(arg0, func_001B9970());
    func_00306780(arg0, D_00827840, MGTShirt__global_00827840);
    func_00306780(arg0, D_00827838, MLoggerControl__global_008212E8);
    {
        Str *ps = &s;
        const char *src = D_006938A0;
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
        func_002F3818(arg0, &s, MGTShirt__clear);
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
        const char *src = D_006938A8;
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
        func_002F3860(arg0, &s, MGTShirt__get_threshold, MGTShirt__set_threshold);
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
        const char *src = D_006938B8;
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
        func_002F3860(arg0, &s, MGTShirt__get_threshold_cr, MGTShirt__set_threshold_cr);
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
        const char *src = D_006938C8;
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
        func_002F3860(arg0, &s, MGTShirt__get_threshold_scan_base, MGTShirt__set_threshold_scan_base);
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
        const char *src = D_006938E0;
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
        func_002F3860(arg0, &s, MGTShirt__get_threshold_scan_step, MGTShirt__set_threshold_scan_step);
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
        const char *src = D_006938F8;
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
        func_002F3860(arg0, &s, MGTShirt__get_threshold_pattern_base, MGTShirt__set_threshold_pattern_base);
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
        const char *src = D_00693910;
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
        func_002F3860(arg0, &s, MGTShirt__get_threshold_pattern_step, MGTShirt__set_threshold_pattern_step);
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
        const char *src = D_00693928;
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
        func_002F3860(arg0, &s, 0, MGTShirt__set_led_start_delay);
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
        const char *src = D_00693938;
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
        func_002F3860(arg0, &s, 0, MGTShirt__set_led_interval);
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
        const char *src = D_00693948;
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
        func_002F3860(arg0, &s, 0, MGTShirt__set_refrect_count);
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
        const char *src = D_00693958;
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
        func_002F3860(arg0, &s, 0, MGTShirt__set_focus);
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
        const char *src = D_00693960;
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
        func_002F3860(arg0, &s, MGTShirt__get_recognizing, MGTShirt__set_recognizing);
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
        const char *src = D_00693970;
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
        func_002F3860(arg0, &s, MGTShirt__get_found, 0);
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
        const char *src = D_00693978;
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
        func_002F3860(arg0, &s, MGTShirt__get_recognized, 0);
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
        const char *src = D_00693988;
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
        func_002F3860(arg0, &s, 0, MGTShirt__set_debug);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
