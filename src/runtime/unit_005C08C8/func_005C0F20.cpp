struct Node { int a; void *b; };
extern char __array_type_info__vtable[];

extern "C" void func_005C0F20(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = __array_type_info__vtable;
    }
}
