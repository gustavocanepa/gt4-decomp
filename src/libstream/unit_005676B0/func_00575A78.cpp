typedef int s32;

struct Table {
    char pad[0x48];
    s32 sorted;
    void *entries;
    s32 count;
};

extern "C" s32 func_00575110(const void *, const void *);
extern "C" void func_005A4BF8(void *, s32, s32, s32 (*)(const void *, const void *));

extern "C" void func_00575A78(Table *t) {
    if (t->sorted != 1) {
        t->sorted = 1;
        func_005A4BF8(t->entries, t->count, 8, func_00575110);
    }
}
