struct Node {
    char pad0[4];
    Node *parent;  /* 0x4 */
    Node *left;    /* 0x8 */
    Node *right;   /* 0xC */
    unsigned key;  /* 0x10 */
};

struct Tree {
    char pad0[4];
    Node *header;  /* 0x4 */
};

extern "C" Node **func_0060C188(Node **arg0, Tree *arg1, unsigned *arg2) {
    Node *a1 = arg1->header;
    Node *v1 = a1->parent;

    if (v1 != 0) {
        unsigned target = *arg2;
        unsigned key = v1->key;
        do {
            if (key >= target) {
                a1 = v1;
                v1 = v1->left;
            } else {
                v1 = v1->right;
            }
            if (v1 != 0) {
                key = v1->key;
            }
        } while (v1 != 0);
    }

    *arg0 = a1;
    return arg0;
}
