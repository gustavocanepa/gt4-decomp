typedef int s32;
typedef unsigned int u32;

struct Slot {
    char data[0x1E0];
};

struct Obj {
    char pad[0x1E5C8];
    Slot slots[2];
};

extern "C" Slot *RaceBase__getInput(Obj *, s32);

extern "C" Slot *RaceSplitBattleBase__getInput(Obj *o, s32 id) {
    u32 k = id - 0x100;
    if (k < 2)
        return &o->slots[k];
    return RaceBase__getInput(o, id);
}
