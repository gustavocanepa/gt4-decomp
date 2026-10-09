struct Node { int a; void *b; };
extern char __ptmf_type_info__vtable[];

extern "C" void func_005C0EE0(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = __ptmf_type_info__vtable;
    }
}
