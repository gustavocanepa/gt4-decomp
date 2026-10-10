typedef int s32;

struct List {
    char pad[0x44];
    s32 count;
};

struct Obj {
    char pad[0x10];
    List list;
    char pad2[0xF0 - 0x10 - sizeof(List)];
    s32 index;
};

extern "C" s32 func_00407A60(List *, s32);

extern "C" s32 func_003DD6D8(Obj *self) {
    List *l = &self->list;
    s32 i = self->index;
    if (i >= l->count)
        return -1;
    return func_00407A60(l, i);
}
