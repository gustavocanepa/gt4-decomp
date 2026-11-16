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
extern "C" void func_0017D268(void *, int) throw();
extern "C" void func_0017D2C0(void *, void *) throw();
extern "C" Hdr *func_001D1280(s32, void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);

extern "C" void MMemoryCardPlayList__append(void **out, void *input, int count, void *arg) {
    Hdr *a[4];
    Hdr *ok = 0;
    func_0017D2C0(a,input);
    if (count > 0) {
        Inner *inner[4];
        Inner **h=inner;

    func_00174148(h, arg);
    Base *b = h[0]->f10;
    s32 v = a[0]->f10;
    void *cast;
    if (b != 0) {
        Entry *e = b->vt;
        cast = __dynamic_cast_2(e->fn, D_005D15A8, 0, (char *)b + e->delta, D_005D1260, b);
    } else {
        cast = 0;
    }
    ok = func_001D1280(v, cast);
    if (ok != 0) a[0]->f18 = 1;
    func_001740F0(h, 2);

    }
    Inner *sp10[4];
    Inner **p=sp10;
    func_002FE278(p, ok != 0);
    if (out != (void **)p) {
        void *nv = p[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*out != 0)
            func_003285F8(*out);
        *out = nv;
    }
    func_002FC870(p, 2);
    func_0017D268(a, 2);
}
