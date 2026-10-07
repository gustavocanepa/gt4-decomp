struct Node { int a; void *b; };
extern char D_0068A340[];

extern "C" void func_005C0EE0(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = D_0068A340;
    }
}
