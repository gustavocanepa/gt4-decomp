typedef unsigned long long u64;
typedef signed char s8;

union Entry {
    struct {
        u64 value : 56;
    } v;
    struct {
        char pad[7];
        s8 kind;
    } k;
};

struct Table {
    Entry entries[400];
    int count;
};

extern "C" void func_001CD8A0(u64 value, int kind);

extern "C" void *func_001D1340(Table *t, int i, void *out) {
    if (i < 0 || i >= t->count)
        return 0;
    func_001CD8A0(t->entries[i].v.value, t->entries[i].k.kind);
    return out;
}
