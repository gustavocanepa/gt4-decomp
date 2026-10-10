/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): an out-of-line (linkonce) copy of a member of the C++ runtime's classes (type_info and its __*_type_info subclasses, exception, bad_alloc, bad_cast, bad_typeid, bad_exception: cp/tinfo.h, typeinfo, exception, new), from the block the runtime's objects brought (0x616370-0x616f24).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef unsigned int u32;

extern "C" void exception__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6308;

extern int D_008A2150;

extern "C" void *bad_exception__tf(void) {
    if (D_008A2150 == 0) {
        exception__tf();
        func_005BFB68(&D_008A2150, ((char *)"13bad_exception"), &D_006D6308);
    }
    return &D_008A2150;
}
