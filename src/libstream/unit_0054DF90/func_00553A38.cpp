typedef int s32;

struct Slot {
    s32 a;
    s32 b;
};

struct Mgr {
    char pad0[0xA4];
    Slot slots[1];
};

struct Item {
    char pad0[0x58];
    s32 index;
    char pad5C[0x8];
    void *data;
};

extern "C" void func_00554058(Mgr *mgr, Slot *slot, void *data, Item *item);

extern "C" void func_00553A38(Mgr *mgr, Item *item) {
    void *data = item->data;
    s32 index = item->index;
    if (data) {
        func_00554058(mgr, &mgr->slots[index], data, item);
    }
}
