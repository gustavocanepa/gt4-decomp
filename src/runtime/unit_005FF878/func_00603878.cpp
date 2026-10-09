typedef int s32;

struct Entry {
    char pad[8];
};

struct BigElem {
    char pad[0x14];
    s32 unk14;
};

struct Obj {
    Entry *arr;
};

extern "C" s32 func_00603878(Obj *arg0, s32 arg1) {
    Entry *base = arg0->arr;
    BigElem *e = (BigElem *)(base + arg1);
    return e->unk14;
}
