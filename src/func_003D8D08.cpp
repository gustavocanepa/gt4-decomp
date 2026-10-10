struct Node {
    char pad0[0x10];
    Node *next;
};

struct List {
    char pad0[0x14];
    Node *first;
};

struct Ctx {
    char pad0[0x60];
    List *list;
};

struct Obj {
    char pad0[0xC];
    Ctx *ctx;
};

extern "C" int func_003D8BE8(Obj *self, Node *node);

extern "C" Node *func_003D8D08(Obj *self) {
    Node *n = self->ctx->list->first;
    for (;;) {
        if (!n)
            return 0;
        if (func_003D8BE8(self, n))
            return n;
        n = n->next;
    }
}
