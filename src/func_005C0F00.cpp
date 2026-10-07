struct Node { int a; void *b; };
extern char D_0068A328[];

extern "C" void func_005C0F00(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = D_0068A328;
    }
}
