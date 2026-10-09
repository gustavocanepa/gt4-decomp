struct Node { int a; void *b; int c; };
extern char __pointer_type_info__vtable[];
void func_005C0E78(struct Node *n, int a, int c)
{
    if (n) {
        n->a = a;
        n->b = __pointer_type_info__vtable;
        n->c = c;
    }
}
