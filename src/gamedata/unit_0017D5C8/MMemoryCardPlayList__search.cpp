/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Entry {
    short delta;
    short index;
    void *fn;
};

struct Base {
    char pad0[0x4C];
    Entry *vt;
};

struct Inner {
    char pad[0x10];
    Base *f10;
};

struct Hdr {
    char pad[0x10];
    s32 f10;
    char pad14[4];
    s32 f18;
};

extern char D_005D15A8[];
extern char D_005D1260[];
extern "C" void func_001740F0(void *, int);
extern "C" s32 func_00174148(void *, void *);
extern "C" void func_0017D268(void *, int);
extern "C" void func_0017D2C0(void *);
extern "C" s32 func_001D13A0(s32, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" s32 __dynamic_cast_2(void *, void *, int, void *, void *, void *);

static inline void store(void **out, Inner **r) {
    if (out != (void **)r) {
        void *nv = r[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*out != 0)
            func_003285F8(*out);
        *out = nv;
    }
}

extern "C" void MMemoryCardPlayList__search(void **out, int unused, int count, void *arg) {
    Hdr *a[4];
    func_0017D2C0(a);
    if (count > 0) {
        Inner *h[4];
        Inner *r[4];
        Inner **ph = h;
        func_00174148(ph, arg);
        Hdr *a0 = a[0];
        Inner *hh = ph[0];
        Base *b = hh->f10;
        s32 v = a0->f10;
        s32 cast = b ? __dynamic_cast_2(b->vt->fn, D_005D15A8, 0, (char *)b + b->vt->delta, D_005D1260, b) : 0;
        s32 res = func_001D13A0(v, cast);
        Inner **pr = r;
        func_002FE278(pr, res);
        store(out, pr);
        func_002FC870(pr, 2);
        func_001740F0(ph, 2);
    } else {
        Inner *r[4];
        Inner **pr = r;
        func_002FE278(pr, -1);
        store(out, pr);
        func_002FC870(pr, 2);
    }
    func_0017D268(a, 2);
}
