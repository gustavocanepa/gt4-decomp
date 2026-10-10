struct Inner {
    char pad[0x60];
    int id;
};

struct Item {
    char pad[0x14];
    int value;
};

struct Obj {
    char pad0[0xC];
    Inner *inner;
    int timer;
    char pad1[0x6C - 0x14];
    int dirty;
    char pad2[0xC4 - 0x70];
    int values[8];
};

extern "C" void RaceEntryBase__sortByRank(int id);
extern "C" Item *func_003D8D08(Obj *o);
extern "C" Item *func_003D8CB8(Obj *o, Item *it);
extern "C" unsigned int DynamicsConductor__CurrentTotalTime(int t);

extern "C" void func_003D9A80(Obj *o)
{
    RaceEntryBase__sortByRank(o->inner->id);
    int i = 0;
    for (Item *it = func_003D8D08(o); it != 0; it = func_003D8CB8(o, it)) {
        int v = it->value;
        if (o->values[i] != v) {
            o->values[i] = v;
            o->dirty = 1;
        }
        i++;
    }
    if (DynamicsConductor__CurrentTotalTime(o->timer) < 1000) {
        o->dirty = 0;
    }
}
