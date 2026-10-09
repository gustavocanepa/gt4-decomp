struct Node { int a; void *b; };
extern char __func_type_info__vtable[];

extern "C" void func_005C0EC0(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = __func_type_info__vtable;
    }
}
