typedef unsigned int u32;

struct Item {
    u32 key;
    void *value;
};

struct Table {
    char pad0[0x4C];
    Item *items;
    int count;
};

extern "C" int func_00575620(Table *t, u32 key) {
    int less = 0;
    int lo = 0;
    int hi = t->count;
    int mid = 0;
    while (lo != hi) {
        mid = (lo + hi) >> 1;
        Item *it = &t->items[mid];
        u32 k = it->key;
        if (k == key)
            return mid;
        less = k < key;
        if (lo == mid)
            break;
        if (less)
            lo = mid;
        else
            hi = mid;
    }
    return ~(mid + less);
}
