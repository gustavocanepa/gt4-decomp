struct Node {
    char pad[0xE8];
    Node *next;
    Node *prev;
};

struct IterData {
    void *owner;
    Node *node;
};

struct Iter {
    IterData d;
    Iter(const Iter &o) : d(o.d) {}
};

struct List {
    char pad[0x1E04];
    Node *end;
    int count;
};

extern "C" void func_00605618(List *l, Node *n);

extern "C" Iter func_006088C0(List *l, Iter pos) {
    Node *n = pos.d.node;
    if (n != l->end) {
        pos.d.node = n->next;
        n->prev->next = n->next;
        n->next->prev = n->prev;
        func_00605618(l, n);
        l->count--;
    }
    return pos;
}
