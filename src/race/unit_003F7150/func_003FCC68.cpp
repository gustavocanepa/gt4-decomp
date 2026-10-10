struct Node { int pad[3]; Node *next; };
struct List { int count; int pad[5]; Node *head; };
extern "C" int func_003FCBA8(Node *);

extern "C" Node *func_003FCC68(List *l, Node *cur)
{
    int n = l->count;
    Node *p = cur;
    for (int i = 0; i < n; i++) {
        p = p->next;
        if (!p) p = l->head;
        if (p && func_003FCBA8(p)) return p;
    }
    return cur;
}
