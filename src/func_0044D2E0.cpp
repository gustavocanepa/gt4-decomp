typedef int s32;

struct Ops {
    s32 (*get)(void);
};

struct Entry {
    char pad0[0x8];
    Ops *ops;
};

extern "C" Entry *func_0044CEB8(s32 id);

extern "C" s32 func_0044D2E0(s32 id) {
    Entry *e = func_0044CEB8(id);
    s32 r = 0;
    if (e) {
        r = e->ops->get();
    }
    return r;
}
