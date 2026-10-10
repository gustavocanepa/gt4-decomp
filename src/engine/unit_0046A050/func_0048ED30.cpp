struct NamedEntry {
    const char *name;
    int value;
};

extern NamedEntry D_00849678[];

extern "C" int func_0057F238(const char *a, const char *b);

extern "C" int func_0048ED30(const char *name) {
    NamedEntry *e = D_00849678;
    for (int i = 0; i < 12; i++, e++) {
        if (func_0057F238(e->name, name) == 0)
            return i;
    }
    return -1;
}
