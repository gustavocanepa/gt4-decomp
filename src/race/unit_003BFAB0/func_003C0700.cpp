struct List {
    unsigned int count;
    int m4;
    void **items;
};

struct Obj {
    char pad[0x60];
    List *list;
};

extern "C" void RaceEntryCar__updateBodyColor(void *item);

extern "C" void func_003C0700(Obj *o) {
    unsigned int n = o->list->count;
    for (unsigned int i = 0; i < n; i++)
        RaceEntryCar__updateBodyColor(o->list->items[i]);
}
