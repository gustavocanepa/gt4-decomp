typedef int s32;

struct Entry_001794A0 {
    s32 value;
    const char *name;
};

extern "C" s32 func_0057F238(const char *a, const char *b);

extern "C" s32 func_001794A0(Entry_001794A0 *e, const char *name) {
    for (; e->name != 0; e++) {
        if (func_0057F238(e->name, name) == 0) {
            return e->value;
        }
    }
    return -1;
}
