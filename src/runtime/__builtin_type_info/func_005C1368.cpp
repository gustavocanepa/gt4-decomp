/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_006599F8;
extern char D_006D30E8[];
extern char __builtin_type_info__vtable[];

extern "C" struct S00659988 *func_005C1368(void) {
    if (D_006599F8.unk0 == 0) {
        D_006599F8.unk0 = D_006D30E8;
        D_006599F8.unk4 = __builtin_type_info__vtable;
    }
    return &D_006599F8;
}
