struct Entry {
    int key;
    void *value;
};

struct Table {
    int pad0[3];
    int count;
    Entry entries[1];
};

extern "C" void func_0048F4E0(Table *self, void (*fn)(void *))
{
    if (fn == 0)
        return;
    int n = self->count;
    for (int i = 0; i < n; i++)
        fn(self->entries[i].value);
}
