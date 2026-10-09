typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mWidget__vtable;
extern "C" void func_00255058(void *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void func_0024B248(void *, s32);
extern "C" void func_005DD9C0(void *);
extern "C" void *func_005DEA88(void);
extern "C" void func_0026A118(void *, s32);
extern "C" void func_003286B8(void *);
extern "C" void hModule__structor_2(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void member_0(char *m) {
    func_0024B248(m + 0x8, 0x2);
    func_005DD9C0(m);
    void *p0 = *(void **)(m + 0x4);
    void *r3 = func_005DEA88();
    func_00326798(p0, 0xc, 0x4, *(void **)(r3));
}

extern "C" void mWidget__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mWidget__vtable;
    func_00255058(*(void **)((char *)arg0 + 0x90));
    str_release((Str *)((char *)arg0 + 0x94));
    str_release((Str *)((char *)arg0 + 0x8c));
    member_0((char *)arg0 + 0x60);
    func_0026A118((char *)arg0 + 0x30, 0x2);
    if (*(void **)((char *)arg0 + 0x2c) != 0) {
        func_003286B8(*(void **)((char *)arg0 + 0x2c));
    }
    hModule__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0xa0, 0x4, "RefCounter");
    }
}
