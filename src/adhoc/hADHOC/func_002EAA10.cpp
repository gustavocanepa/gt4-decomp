typedef int s32;

struct Node {
    s32 color;
    Node *parent;
    Node *left;
    Node *right;
    s32 key;
    s32 value;
};

struct Iter {
    Node *node;
    Node *operator->() const { return node; }
};

struct Map {
    s32 alloc;
    Node *header;
};

struct Obj {
    s32 a;
    s32 b;
    Map m;
};

extern "C" Iter func_005EAC20(Map *, s32);

extern "C" s32 func_002EAA10(Obj *self, s32 key) {
    Map *m = &self->m;
    Iter it = func_005EAC20(m, key);
    if (it.node == m->header)
        return 0;
    return it->value;
}
