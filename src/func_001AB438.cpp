struct Item {
    char data[0x14];
};

struct List {
    Item items[32];
    int count;
};

struct Obj {
    void *ctx;
    char pad4[0x28];
    List list;
};

extern "C" void func_001AB110(void *ctx, Item *it, int arg);

extern "C" void func_001AB438(Obj *o, int arg) {
    List *l = &o->list;
    void *ctx = o->ctx;
    for (int i = 0; i < l->count; i++)
        func_001AB110(ctx, &l->items[i], arg);
}
