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

struct Obj {
    char pad[0x10];
    s32 p10;
};

struct OHandle {
    Obj *p;
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0xC];
};

extern Rep D_00659FA8;

extern "C" void func_001711F0(void *arg0, int arg1);
extern "C" void *func_00171248(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" int func_002FE250(void *arg0);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" const char *func_004322C8(s32 arg0, s32 arg1);
extern "C" void func_00432328(s32 arg0, char *buf, s32 arg2, s32 arg3);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

extern "C" void MLicenseRecordUnit__getPassCode(s32 *arg0, void *arg1, s32 arg2, char *arg3) {
    OHandle tmp;
    union {
        Handle h2;
        s32 arr1[4];
    } u;
    char buf[0x10];
    s32 buf0[4];
    Str s;
    Str s2;
    Str *ps;
    s32 newVal;
    s32 oldVal;
    s32 *pb;
    s32 v = 0;

    if (arg2 > 0) {
        func_002FC8C8(&tmp, arg3);
        v = func_002FE250(tmp.p);
        func_002FC870(&tmp, 2);
    }
    func_00171248(&tmp, arg1);
    if (arg2 >= 2) {
        Handle *ph2 = &u.h2;
        s32 p10;
        s32 r;
        func_002FC8C8(ph2, arg3 + 4);
        p10 = tmp.p->p10;
        r = func_002FE250(ph2->p);
        func_00432328(p10, buf, v, r);
        {
            Rep *rep = &D_00659FA8;
            char *d;
            ps = &s;
            if (rep->sel != 0) {
                d = func_005C2560(rep);
            } else {
                d = (char *)(rep + 1);
                rep->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, buf, func_0057F260(buf));
        pb = buf0;
        func_00314B20(pb, ps);
        if (arg0 != pb) {
            newVal = *pb;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00312318(pb, 2);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_002FC870(ph2, 2);
    } else {
        const char *src;
        ps = &s2;
        src = func_004322C8(tmp.p->p10, v);
        {
            Rep *rep = &D_00659FA8;
            char *d;
            if (rep->sel != 0) {
                d = func_005C2560(rep);
            } else {
                d = (char *)(rep + 1);
                rep->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        pb = u.arr1;
        func_00314B20(pb, ps);
        if (arg0 != pb) {
            newVal = *pb;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00312318(pb, 2);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    func_001711F0(&tmp, 2);
}
