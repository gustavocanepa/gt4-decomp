typedef int s32;

struct Node {
    s32 a;
    s32 b;
    Node *next;
};

struct List {
    Node *head;
};

extern "C" s32 func_0057CAB8(List *l, Node *n) {
    Node *p;
    if (n != 0) {
        for (p = l->head; p != 0; p = p->next) {
            if (p == n)
                return 1;
        }
    }
    return 0;
}
