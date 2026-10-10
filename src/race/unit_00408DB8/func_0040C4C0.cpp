struct Node { char pad[0x10]; Node *next; int value; };
struct List { char pad[0x14]; Node *first; };
struct Src { char pad[0x60]; List *list; };
extern "C" void ResultArcade__setCarName(void *ctx, int i, Node *n);
extern "C" void ResultArcade__setCarIconNumber(void *ctx, int i, int v);

extern "C" void func_0040C4C0(void *ctx, Src *s)
{
    int i = 0;
    for (Node *n = s->list->first; n; n = n->next) {
        ResultArcade__setCarName(ctx, i, n);
        ResultArcade__setCarIconNumber(ctx, i, n->value);
        i++;
    }
}
