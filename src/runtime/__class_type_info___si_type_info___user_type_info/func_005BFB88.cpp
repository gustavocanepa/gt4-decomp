struct Node { int a; void *b; };
extern char __user_type_info__vtable[];

extern "C" void func_005BFB88(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = __user_type_info__vtable;
    }
}
