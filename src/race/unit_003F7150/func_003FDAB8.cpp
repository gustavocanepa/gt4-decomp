/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item {
    char data[0x7C];
};

struct Table {
    char pad0[0x20];
    int count;
    Item *items;
};

struct Inner {
    int unk0;
    char pad4[0xBC];
    Table *table;
};

struct Outer {
    int unk0;
    Inner *inner;
};

struct Obj {
    char pad0[0x80];
    Outer *outer;
};

struct Cursor {
    int unk0;
    Table *table;
    Item *item;
    int unkC;
};

extern "C" int func_003FDAB8(Obj *self, int index, Cursor *c, int wrap) {
    int wrapped = 0;
    Table *t = self->outer->inner->table;
    int count = t->count;
    c->table = t;
    c->item = 0;
    c->unkC = 0;
    c->unk0 = 0;
    if (index >= count) {
        if (!wrap)
            return 0;
        index = 0;
        wrapped = 1;
    }
    c->item = &t->items[index];
    return wrapped;
}
