typedef int s32;

struct Entry {
    char pad[4];
};

struct BigElem {
    char pad[0x10];
    s32 unk10;
};

struct Obj {
    Entry *arr;
};

extern "C" s32 func_00603B00(Obj *arg0, s32 arg1) {
    Entry *base = arg0->arr;
    BigElem *e = (BigElem *)(base + arg1);
    return e->unk10;
}
