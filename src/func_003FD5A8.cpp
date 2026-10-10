struct Item {
    char pad0[0x14];
    int m14;
};

struct Node {
    char pad0[0x10];
    Item *cur;
};

struct List;

struct Obj {
    char pad0[0x60];
    List *list;
};

extern "C" Item *func_003FCBD0(List *l, Item *i);
extern "C" Item *func_003FCC68(List *l, Item *i);
extern "C" void func_003FC4F0(Node *n, int v);

extern "C" int func_003FD5A8(Obj *o, Node *n, int next) {
    List *l = o->list;
    if (!n->cur)
        return 0;
    Item *i;
    if (next)
        i = func_003FCBD0(l, n->cur);
    else
        i = func_003FCC68(l, n->cur);
    if (!i)
        return 0;
    if (i == n->cur)
        return 0;
    func_003FC4F0(n, i->m14);
    return 1;
}
