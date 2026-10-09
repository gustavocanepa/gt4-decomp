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
    char pad[0xC];
};

extern "C" void func_0021D978(void *arg0, int arg1);
extern "C" void func_0021D9D0(void *arg0, void *arg1);
extern "C" void func_0021FB30(Str *ret, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
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

extern "C" void MMovieFace__get_movie_name(void **arg0, void *arg1) {
    Handle o;
    Handle h;
    Str s;
    Str *ps;
    Handle *ph;

    func_0021D9D0(&o, arg1);
    ps = &s;
    func_0021FB30(ps, o.p);
    ph = &h;
    func_00314B20(ph, ps);
    if ((void *)arg0 != (void *)ph) {
        void *p = ph->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = p;
    }
    func_00312318(ph, 2);
    str_release(ps);
    func_0021D978(&o, 2);
}
