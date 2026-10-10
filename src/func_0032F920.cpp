typedef int s32;
typedef unsigned int u32;

struct Slot {
    char data[0x1E0];
};

struct Obj {
    char pad[0x1E5C8];
    Slot slots[2];
};

extern "C" Slot *func_00389628(Obj *, s32);

extern "C" Slot *func_0032F920(Obj *o, s32 id) {
    u32 k = id - 0x100;
    if (k < 2)
        return &o->slots[k];
    return func_00389628(o, id);
}
