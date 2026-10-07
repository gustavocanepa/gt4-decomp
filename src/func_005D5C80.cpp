typedef int s32;

struct Node {
    s32 color;
    Node *parent;
    Node *left;
    Node *right;
    char value[4];
};

struct Tree {
    s32 pad0;
    Node *header;
};

struct It {
    Node *node;
};

extern "C" s32 func_005C2A50(const void *a, const void *b, s32 pos, s32 n);

static inline bool less(const void *a, const void *b) {
    return func_005C2A50(a, b, 0, -1) < 0;
}

static inline Node *hdr(Tree *t) { return t->header; }
static inline Node *root(Tree *t) { return t->header->parent; }
static inline void ctor(It *i, Node *n) { i->node = n; }
static inline It end(Tree *t) { It r; r.node = t->header; return r; }

extern "C" It func_005D5C80(Tree *t, const void *k) {
    Node *y = hdr(t);
    Node *x = root(t);
    while (x != 0) {
        if (!less(x->value, k)) {
            y = x;
            x = x->left;
        } else {
            x = x->right;
        }
    }
    It j;
    ctor(&j, y);
    It r;
    r.node = (j.node == hdr(t) || less(k, j.node->value)) ? hdr(t) : j.node;
    return r;
}
