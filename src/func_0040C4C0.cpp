struct Node { char pad[0x10]; Node *next; int value; };
struct List { char pad[0x14]; Node *first; };
struct Src { char pad[0x60]; List *list; };
extern "C" void func_003DFBC8(void *ctx, int i, Node *n);
extern "C" void func_003DFC28(void *ctx, int i, int v);

extern "C" void func_0040C4C0(void *ctx, Src *s)
{
    int i = 0;
    for (Node *n = s->list->first; n; n = n->next) {
        func_003DFBC8(ctx, i, n);
        func_003DFC28(ctx, i, n->value);
        i++;
    }
}
