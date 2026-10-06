struct Node { int a; void *b; int c; };
extern char D_0068A258[];
void func_005BFB68(struct Node *n, int a, int c)
{
    if (n) {
        n->a = a;
        n->b = D_0068A258;
        n->c = c;
    }
}
