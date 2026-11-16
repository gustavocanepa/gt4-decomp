struct VEntry {
    short delta;
    short pad2;
    void *tf;
};

struct Node {
    char pad0[4];
    VEntry *e;
    char pad1[0x4C];
    Node *next;
};

extern "C" int func_0025C110(Node *arg0);
extern "C" int __dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern char mProject__tf[];
extern char mWidget__tf[];

extern "C" int func_0025C178(Node *self) {
    int r;
    if (self->next != 0)
        return func_0025C110(self->next);
    if (self != 0) {
        VEntry *e = self->e;
        r = __dynamic_cast_2(e->tf, mProject__tf, 0, (char *)self + e->delta, mWidget__tf, self);
    } else {
        r = 0;
    }
    return r;
}
