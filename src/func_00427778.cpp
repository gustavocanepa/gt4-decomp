struct Item {
    const char *name;
    int pad[3];
};

struct Table {
    char pad[0x16];
    unsigned short count;
    int pad18;
    Item *items;
};

extern "C" int func_0057F238(const char *a, const char *b);

extern "C" int func_00427778(Table *t, const char *name) {
    for (int i = 0; i < t->count; i++) {
        if (func_0057F238(t->items[i].name, name) == 0)
            return i;
    }
    return -1;
}
