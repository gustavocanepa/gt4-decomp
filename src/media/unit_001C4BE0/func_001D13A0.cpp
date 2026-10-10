struct Key {
    unsigned long long hash : 56;
    signed char tag;
    bool operator==(const Key &o) const {
        if (hash != o.hash)
            return false;
        return tag == o.tag;
    }
};

extern "C" void func_001D1478(Key *key, const char *name);

struct Table {
    Key keys[400];
    int count;
};

extern "C" int func_001D13A0(Table *t, const char *name) {
    if (!name)
        return -1;
    Key key;
    func_001D1478(&key, name);
    for (int i = 0; i < t->count; i++) {
        if (key == t->keys[i])
            return i;
    }
    return -1;
}
