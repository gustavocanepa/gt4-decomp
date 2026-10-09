struct Node { int a; void *b; };
extern char __ptmd_type_info__vtable[];

extern "C" void func_005C0F00(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = __ptmd_type_info__vtable;
    }
}
