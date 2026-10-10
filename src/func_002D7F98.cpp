struct Node;
extern "C" Node *func_0025C300(Node *n);
extern "C" void func_002D7EB8(void *self, void *pos, Node *first, Node *last, int count);

extern "C" void func_002D7F98(void *self, void *pos, Node *first, Node *last) {
    int count = 0;
    for (Node *p = first; p != last; p = func_0025C300(p))
        count++;
    return func_002D7EB8(self, pos, first, last, count);
}
