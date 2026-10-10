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
};

union U {
    Str s;
    s32 h[4];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

extern char D_0068E7F8[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int func_004487D8(const char *arg0, s32 *dest);
extern "C" s16 func_00448868(s32 *arg0);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_0068E7F8;
    }
    s->p[len] = 0;
    return s->p;
}

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}


extern Rep D_00659FA8;
extern char D_0068E830[], D_0068E838[];
extern "C" char *func_005C2560(Rep *arg0);
extern "C" s32 func_0057F260(const char *arg0);
extern "C" void func_005C2630(Str *arg0, s32 pos, s32 n, const char *text, s32 length);
extern "C" void func_00314B20(void *arg0, Str *arg1);
extern "C" void func_00312318(void *arg0, s32 arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" const char *func_00314AD8(s32 arg0);
static inline void empty(Str *s) {
    Rep *q = &D_00659FA8;
    char *p;
    if (q->sel != 0) {
        p = func_005C2560(q);
    } else {
        q->ref = q->ref + 1;
        p = (char *)(q + 1);
    }
    s->p = p;
}

extern char D_0068E800[], D_0068E828[];
extern "C" Str *func_00314920(s32);
extern "C" const char *func_00447E18(const char *);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" unsigned int func_00448540(s32, char *, s32);
extern "C" s32 func_00447BB8(const char *);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" s32 func_005A5AD8(const char *, const char *, long long *);
extern "C" void func_004481B8(long long, char *);
extern "C" void func_00448200(const char *, char *);
extern "C" void func_00448278(const char *, char *);
extern "C" void func_005A48D8(void *, s32, s32);
struct Seed { long long a; s32 b; } __attribute__((packed));
extern Seed D_0068E818;

extern "C" void MCarData__GetCarNameByNumericCode(s32 *arg0, s32 arg1, void *arg2) {
    if (arg1 > 0) {
        long long code;
        U u;
        char buf[144];
        Str str;
        U *pu;
        Str *ps;
        const char *value;
        s32 newVal, oldVal;
        pu = &u;
        func_00312370(pu, arg2);
        func_005A5AD8(func_00314AD8(pu->h[0]), D_0068E828, &code);
        func_00312318(pu, 2);
        func_004481B8(code, buf);
        value = buf;
        ps = &str;
        empty(ps);
        func_005C2630(ps, 0, -1, value, func_0057F260(value));
        func_00314B20(pu, ps);
        if (arg0 != pu->h) {
            newVal = pu->h[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00312318(pu, 2);
        release(ps);
    }
}
