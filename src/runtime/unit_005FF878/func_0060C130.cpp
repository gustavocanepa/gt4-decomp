struct D_Node {
    char pad[8];
    D_Node *next;
    D_Node *child;
};

extern "C" void func_00575DA0(void *);

extern "C" void func_0060C130(int arg0, D_Node *node) {
    if (node) {
        do {
            func_0060C130(arg0, node->child);
            D_Node *next = node->next;
            func_00575DA0(node);
            node = next;
        } while (node);
    }
}
