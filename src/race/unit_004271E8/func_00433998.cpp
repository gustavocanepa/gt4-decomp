struct Item {
    char pad[0x238];
};

struct ItemList {
    int pad0;
    Item *items;
    int count;
};

extern "C" void func_00432F70(Item *item);
extern "C" void func_00432EB8(Item *item);

extern "C" void func_00433998(ItemList *l, Item *items, int count, int selected) {
    l->items = items;
    l->count = count;
    for (int i = 0; i < l->count; i++) {
        if (i == selected)
            func_00432F70(&l->items[i]);
        else
            func_00432EB8(&l->items[i]);
    }
}
