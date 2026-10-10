struct Entry {
    int key;
    void *data;
    int size;
    int padC;
};

struct Table {
    char pad0[0xC];
    unsigned int count;
    Entry entries[1];
};

extern "C" void *func_005A3008(const void *key, const void *base, unsigned int n, unsigned int size,
                               int (*compar)(const void *, const void *)); /* bsearch */
extern "C" int func_0048F1C0(const void *a, const void *b);

extern "C" void *func_0048F1D8(Table *t, const void *key, int *size) {
    Entry *e = (Entry *)func_005A3008(key, t->entries, t->count, sizeof(Entry), func_0048F1C0);
    if (!e)
        return 0;
    if (size)
        *size = e->size;
    return e->data;
}
