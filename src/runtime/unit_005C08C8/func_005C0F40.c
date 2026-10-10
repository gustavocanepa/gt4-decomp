/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __dynamic_cast (cp/tinfo2.cc).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* __dynamic_cast (gcc/cp/tinfo2.cc, old ABI): abort() unless require_public, then
   __user_type_info::dyncast (func_005BFC20) on from() with boff -1, to(), address, sub(), subptr. */
extern void func_005A2E68(void) __attribute__((noreturn)); /* abort */
extern void *func_005BFC20(void *self, int boff, void *target, void *objptr, void *subtype,
                           void *subptr);

void *func_005C0F40(void *(*from)(void), void *(*to)(void), int require_public, void *address,
                    void *(*sub)(void), void *subptr)
{
    void *self, *target;
    if (!require_public) func_005A2E68();
    self = from();
    target = to();
    return func_005BFC20(self, -1, target, address, sub(), subptr);
}
