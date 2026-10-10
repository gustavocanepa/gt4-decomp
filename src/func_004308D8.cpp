extern "C" int func_0057F238(const char *a, const char *b);

extern "C" int func_004308D8(const char *name, const char **list, int count) {
    for (int i = 0; i < count; i++) {
        if (func_0057F238(name, list[i]) == 0)
            return i;
    }
    return -1;
}
