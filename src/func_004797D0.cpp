typedef unsigned short u16;

struct Entry {
    int unk0;
    int unk4;
    u16 id;
    u16 padA;
};

struct Table {
    Entry *data;
    int count;
};

extern "C" Entry *func_004797D0(Table *t, u16 id) {
    Entry *end = t->data + t->count;
    for (Entry *e = t->data; e != end; e++) {
        if (e->id == id)
            return e;
    }
    return 0;
}
