struct Entry {
    char pad[0x44];
    const char *name;
    char pad48[8];
};

struct Key {
    const char *name;
    Entry *base;
    unsigned char flag;
};

struct Less {};

extern "C" Entry *func_00604908(Entry *first, Entry *last, const Key &key, Less comp, int *dist);
extern "C" int func_0057F238(const char *a, const char *b) throw();

extern "C" Entry *func_006045A0(const char *name, Entry *table, int count) {
    Key key;
    key.name = name;
    key.base = table;
    key.flag = 0;
    Entry *end = table + count;
    Entry *it = func_00604908(table, end, key, Less(), 0);
    if (it != end && func_0057F238(it->name, key.name) == 0)
        return it;
    return 0;
}
