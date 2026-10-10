struct Entry {
    const char *name;
    int value;
};

struct Table {
    int f0;
    int count;
    Entry *entries;
};

extern "C" int func_00485F88(const void *a, const void *b);
extern "C" void *func_005A3008(const void *key, const void *base, unsigned int n, unsigned int size,
                               int (*cmp)(const void *, const void *));

extern "C" int func_00485FA0(Table *t, const char *name) {
    if (!name) {
        return 0;
    }
    if (!*name) {
        return 0;
    }
    Entry *e = (Entry *)func_005A3008(name, t->entries, t->count, sizeof(Entry), func_00485F88);
    if (e) {
        return e->value;
    }
    return 0;
}
