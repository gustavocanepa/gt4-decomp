/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
struct Node { int a; void *b; };
extern char __user_type_info__vtable[];

extern "C" void func_005BFB88(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = __user_type_info__vtable;
    }
}
