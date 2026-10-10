struct Entry { const char *name; int value; };
struct Key {
    const char *name;
    Entry *base;
    unsigned char exact;
};
struct Less {};
extern "C" Entry *func_00604840(Entry *first, Entry *last, const Key &k, Less c, int *dist);
extern "C" int func_0057F238(const char *a, const char *b) throw();

extern "C" Entry *func_006044B0(const char *name, Entry *table, int count)
{
    Entry *last = table + count;
    Key k;
    k.name = name;
    k.base = table;
    k.exact = 0;
    Entry *it = func_00604840(table, last, k, Less(), 0);
    if (it != last && func_0057F238(it->name, k.name) == 0)
        return it;
    return 0;
}
