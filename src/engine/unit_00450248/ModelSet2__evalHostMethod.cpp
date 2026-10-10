struct Entry {
    int pad0;
    unsigned short pad4;
    unsigned short slot;
};

struct Def {
    char pad0[0x24];
    unsigned short count;
    char pad26[0x26];
    Entry *entries;
    const Entry &entry(int i) const { return entries[i]; }
};

typedef void (*Fn)(int *data, void *arg);

struct Inst {
    char pad0[0xC];
    int *data;
    Fn *funcs;
};

extern "C" void ModelSet2__evalHostMethod(Def *d, Inst *in, void *arg) {
    for (int i = 0; i < d->count; i++) {
        Fn *f = &in->funcs[i];
        int *p = &in->data[d->entry(i).slot];
        if (*f)
            (*f)(p, arg);
    }
}
