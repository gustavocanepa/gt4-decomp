struct Node {
    char pad0[4];
    Node *prev;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

extern "C" void func_0057CB00(List *arg0, Node *arg1) {
    arg1->prev = arg0->tail;
    arg1->next = 0;
    if (arg0->tail != 0) {
        arg0->tail->next = arg1;
    } else {
        arg0->head = arg1;
    }
    arg0->tail = arg1;
}
