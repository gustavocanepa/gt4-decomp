struct VEntry {
    short delta;
    short index;
    void *fn;
};

struct VObj {
    int pad;
    VEntry *vtbl;
};

static inline int vcallInt(VObj *o) {
    VEntry *e = &o->vtbl[11];
    return ((int (*)(void *))e->fn)((char *)o + e->delta);
}

static inline float vcallFloat(VObj *o) {
    VEntry *e = &o->vtbl[12];
    return ((float (*)(void *))e->fn)((char *)o + e->delta);
}

extern "C" void func_0032B618(void *out, const void *data, int size);

extern "C" void func_002EF070(int type, VObj **args, void *out) {
    char c;
    short s;
    int i;
    long long l;
    float f;
    switch (type) {
    case 'C':
    case 'c':
        c = vcallInt(args[0]);
        func_0032B618(out, &c, 1);
        break;
    case 'S':
    case 's':
        s = vcallInt(args[0]);
        func_0032B618(out, &s, 2);
        break;
    case 'I':
    case 'i':
        i = vcallInt(args[0]);
        func_0032B618(out, &i, 4);
        break;
    case 'L':
    case 'l':
        l = vcallInt(args[0]);
        func_0032B618(out, &l, 4);
        break;
    case 'f':
        f = vcallFloat(args[0]);
        func_0032B618(out, &f, 4);
        break;
    }
}
