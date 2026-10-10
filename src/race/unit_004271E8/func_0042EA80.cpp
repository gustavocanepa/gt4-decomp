typedef int s32;

struct Key {
    s32 a, b;
};

struct Obj {
    char pad[0x2408];
    s32 flag;
};

extern "C" void *func_005A3008(const void *, const void *, s32, s32, s32 (*)(const void *, const void *));
extern "C" s32 func_0042EA58(const void *, const void *);

extern "C" s32 func_0042EA80(Obj *self, Key key, void *table, s32 count) {
    if (self->flag != 0)
        return 1;
    return func_005A3008(&key, table, count, 8, func_0042EA58) != 0;
}
