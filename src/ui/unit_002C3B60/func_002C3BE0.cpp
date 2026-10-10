struct Node;

struct Obj {
    char pad0[0x10];
    Node *root;
    Node *found;
    char key[0x10];
};

extern "C" Node *func_004608C8(Node *root, int on, void *key);

extern "C" void func_002C3BE0(Obj *o, int on) {
    void *key = o->key;
    Node *n = o->root;
    if (n) {
        n = func_004608C8(n, on, key);
        if (!on) {
            n = 0;
        }
        o->found = n;
    }
}
