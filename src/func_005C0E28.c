/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __is_pointer (cp/tinfo2.cc).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* __is_pointer (gcc/cp/tinfo2.cc, old ABI): dynamic_cast<const __pointer_type_info *>(t) != 0,
   with the __dynamic_cast call (func_005C0FC8) spelled out. */
struct VEntry { short delta; short index; void *pfn; };
struct Obj { int pad; struct VEntry *vptr; };

extern char __pointer_type_info__tf[];
extern char type_info__tf[];
void *func_005C0FC8(void *from, void *to, int require_public, void *address, void *sub, void *subptr);

int func_005C0E28(struct Obj *t)
{
    void *pt = 0;
    if (t)
        pt = func_005C0FC8(t->vptr[0].pfn, __pointer_type_info__tf, 0, (char *)t + t->vptr[0].delta, type_info__tf, t);
    return pt != 0;
}
