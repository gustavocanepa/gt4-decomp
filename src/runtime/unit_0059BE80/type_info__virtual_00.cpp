/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
struct S {
    char pad[0x4];
    int unk4;
};

extern void func_005C1628(S *);
extern int type_info__vtable;

void type_info__virtual_00(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk4 = (int)&type_info__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
