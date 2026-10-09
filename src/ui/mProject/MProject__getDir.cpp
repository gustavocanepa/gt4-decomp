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
    char pad[12];
};

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_002292A0(void *arg0, int arg1);
extern "C" void func_002292F8(void *arg0, void *arg1);
extern "C" void func_00229D18(Str *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

extern "C" void MProject__getDir(void **arg0, void *arg1) {
    Handle r[2];
    Str s;
    Handle h;


    Handle *ph = &h;
    Str *ps = &s;
    func_002292F8(ph, arg1);
    func_00229D18(ps, ph->p);
    func_00314B20(r, ps);
    if ((void *)arg0 != (void *)r) {
        void *p = r[0].p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = p;
    }
    func_00312318(r, 2);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_002292A0(ph, 2);
}
