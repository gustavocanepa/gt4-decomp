typedef int s32;

struct Entry {
    s32 key;
    void *value;
};

extern "C" void *func_00179460(Entry *e, s32 key) {
    for (; e->value != 0; e++) {
        if (e->key == key)
            return e->value;
    }
    return 0;
}
