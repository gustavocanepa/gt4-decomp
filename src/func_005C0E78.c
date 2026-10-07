struct Node { int a; void *b; int c; };
extern char D_0068A3A0[];
void func_005C0E78(struct Node *n, int a, int c)
{
    if (n) {
        n->a = a;
        n->b = D_0068A3A0;
        n->c = c;
    }
}
