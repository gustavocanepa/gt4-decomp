struct Node { int a; void *b; int c; };
extern char __si_type_info__vtable[];
void func_005BFB68(struct Node *n, int a, int c)
{
    if (n) {
        n->a = a;
        n->b = __si_type_info__vtable;
        n->c = c;
    }
}
