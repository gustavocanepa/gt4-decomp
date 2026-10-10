typedef int s32;
typedef unsigned long long u64;

struct Item { u64 key; u64 value; };
struct Table { char pad[0x30]; Item *items; char pad34[4]; s32 count; };

extern "C" s32 func_004859A0(Table *t, u64 key) {
    s32 i;
    for (i = 0; i < t->count; i++) {
        u64 k = t->items[i].key;
        if (key == k)
            return i;
        if (k < key)
            break;
    }
    return ~i;
}
