typedef int s32;

struct Str {
    char *p;
};

struct Node {
    s32 color;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
    Str value;
};

struct Tree {
    s32 unk0;
    Node *header;
};

struct Iter {
    Node *node;
    char pad[0xC];
};

extern "C" s32 func_005C2A50(Str *a, Str *b, s32 pos, s32 n);

static inline s32 iter_eq(const Iter *a, const Iter *b) {
    return a->node == b->node;
}

static inline Node *hdr(Tree *t) { return t->header; }
static inline void mk(Iter *i, Node *n) { i->node = n; }

extern "C" Iter *func_005D91C8(Iter *ret, Tree *t, Str *k) {
    Node *y = hdr(t);
    Node *x = y->parent;
    Iter j;
    Iter e;

    while (x != 0) {
        if (!(func_005C2A50(&x->value, k, 0, -1) < 0)) {
            y = x;
            x = x->left;
        } else {
            x = x->right;
        }
    }
    mk(&j, y);
    mk(&e, hdr(t));
    ret->node = (iter_eq(&j, &e) || func_005C2A50(k, &j.node->value, 0, -1) < 0) ? hdr(t) : j.node;
    return ret;
}
