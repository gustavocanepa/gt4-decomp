struct Entry {
    char pad0[0x18];
    const char *name;
    int pad1C;
};

struct List {
    int m0;
    Entry *first;
};

extern "C" int func_0057F238(const char *a, const char *b);

extern "C" int func_0042A428(List *l, Entry *end, const char *name) {
    for (Entry *e = end - 1; e >= l->first; e--) {
        if (e->name && func_0057F238(name, e->name) == 0)
            return 1;
    }
    return 0;
}
