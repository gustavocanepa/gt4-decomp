/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
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
