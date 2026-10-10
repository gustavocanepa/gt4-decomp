struct Entry {
    short id;
    short pad;
    int value;
};

struct Table {
    int unk0;
    int unk4;
    Entry entries[256];
    unsigned char refs[0x1C];
    int count;
};

extern "C" void func_003B7498(Table *t, int index) throw();

extern "C" int func_003B7668(Table *t, int id, int *value, int remove) {
    if (t->refs[id] == 0)
        return 0;
    for (int i = 0; i < t->count; i++) {
        if (t->entries[i].id == id) {
            if (value)
                *value = t->entries[i].value;
            if (remove)
                func_003B7498(t, i);
            return 1;
        }
    }
    return 0;
}
