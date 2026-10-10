/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};
struct Item { char pad[0x14]; int index; };
struct List {
    int count;
    int m4;
    Item **items;
    char pad[0x20 - 0xC];
    VEntry *vtbl;
    int canAdd()
    {
        VEntry *e = &vtbl[4];
        return e->fn((char *)this + e->delta);
    }
};

extern "C" int func_003B6D58(List *l, Item *it)
{
    if (!l->canAdd())
        return -1;
    l->items[l->count] = it;
    it->index = l->count;
    return l->count++;
}
