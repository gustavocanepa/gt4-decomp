/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {
    int color;
    Node *parent;
    Node *left;
    Node *right;
    unsigned int key;
};
struct Iter {
    Node *node;
    Iter() {}
    Iter(Node *n) : node(n) {}
    bool operator==(const Iter &o) const { return node == o.node; }
};
struct func_005DDC38 {
    int alloc;
    Node *header;
    Iter end() { return Iter(header); }
    Iter find(const unsigned int &k);
};

Iter func_005DDC38::find(const unsigned int &k)
{
    Node *y = header;
    Node *x = header->parent;
    while (x != 0)
        if (!(x->key < k))
            y = x, x = x->left;
        else
            x = x->right;
    Iter j = Iter(y);
    return (j == end() || k < j.node->key) ? end() : j;
}
