/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {
    char pad0[0xA8];
    Node *prev;
    Node *next;
};

struct Iter {
    int f0;
    Node *node;
};

struct List {
    char pad0[0x588];
    int count;
};

extern "C" Node *func_005FD458(List *l, Node *prev, Node *next);

extern "C" void func_005FD168(List *l, Iter *pos) {
    Node *p = pos->node;
    Node *n = func_005FD458(l, p, p->next);
    l->count++;
    p->next = n;
    n->next->prev = n;
}
