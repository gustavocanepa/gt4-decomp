struct Node {
    int type;
    int value;
};

extern "C" void func_00476C98(Node *n, int value);
extern "C" void func_00477068(Node *n, int value);
extern "C" int func_004772A8(Node *n);
extern "C" void func_00476A98(Node *n, int value);

extern "C" void func_004767E8(Node *n) {
    if (n->type == 13)
        return func_00476C98(n, n->value);
    if (n->type == 7)
        return func_00477068(n, n->value);
    if (n->type == 3)
        func_00476A98(n, func_004772A8(n));
}
