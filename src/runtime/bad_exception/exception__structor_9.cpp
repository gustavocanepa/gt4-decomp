/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): an out-of-line (linkonce) copy of a member of the C++ runtime's classes (type_info and its __*_type_info subclasses, exception, bad_alloc, bad_cast, bad_typeid, bad_exception: cp/tinfo.h, typeinfo, exception, new), from the block the runtime's objects brought (0x616370-0x616f24).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int exception__vtable;

void exception__structor_9(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&exception__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
