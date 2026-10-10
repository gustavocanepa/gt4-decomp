struct Entry {
    void *get() { return item; }
    char pad[0x14];
    void *item;
};

struct List {
    Entry *entries;
    unsigned int count;
};

extern "C" void func_0045FD48(void *item);

extern "C" void func_0045FD88(List *l) {
    for (unsigned int i = 0; i < l->count; i++)
        func_0045FD48(l->entries[i].get());
}
