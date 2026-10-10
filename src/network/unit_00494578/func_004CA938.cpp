/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { short m0; unsigned short refs; };
struct Node { Node *next; Node *prev; Buf *data; };
extern "C" void *func_00575E60(int, int);
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct It {
    Node *n;
    It(Node *x) : n(x) {}
    It(const It &o) : n(o.n) {}
};
struct List {
    int a0, a4;
    Node *node;
    It end() { return node; }
    It insert(It pos, Buf *const &x)
    {
        Node *tmp = (Node *)func_00575E60(0x10, 0xC);
        new (&tmp->data) Buf *(x);
        tmp->next = pos.n;
        tmp->prev = pos.n->prev;
        pos.n->prev->next = tmp;
        pos.n->prev = tmp;
        return tmp;
    }
    void push_back(Buf *const &x) { insert(end(), x); }
};

extern "C" void func_004CA938(List *l, Buf *b)
{
    if (b->refs == 0) return;
    b->refs--;
    if (b->refs != 0) return;
    l->push_back(b);
}
