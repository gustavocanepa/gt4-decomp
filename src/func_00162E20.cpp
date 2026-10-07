typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
};

struct Obj {
    char pad[0x10];
    char *p10;
};

extern char D_006901F0[];

extern "C" void func_0015F388(void *arg0, int arg1);
extern "C" void *func_0015F3E0(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" Str *func_00314920(s32 arg0);
extern "C" void func_0042FBB0(char *arg0, const char *arg1);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_006901F0;
    s->p[len] = 0;
    return s->p;
}

static inline void call(char *p, const char *t) {
    func_0042FBB0(p, t);
}

extern "C" void func_00162E20(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 > 0) {
        Obj *tmp[4];
        s32 buf[4];
        s32 *pb;
        char *base;
        func_0015F3E0(tmp, arg1);
        pb = buf;
        func_00312370(pb, arg3);
        base = tmp[0]->p10;
        call(base + 0x3A368, c_str(func_00314920(*pb)));
        func_00312318(pb, 2);
        func_0015F388(tmp, 2);
    }
}
