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

extern "C" s32 func_00604090(Obj *arg0, s32 arg1) {
    return ((BigElem *)&arg0->arr[arg1])->unk10;
}
