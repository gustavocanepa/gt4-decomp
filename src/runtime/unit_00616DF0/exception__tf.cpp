/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): an out-of-line (linkonce) copy of a member of the C++ runtime's classes (type_info and its __*_type_info subclasses, exception, bad_alloc, bad_cast, bad_typeid, bad_exception: cp/tinfo.h, typeinfo, exception, new), from the block the runtime's objects brought (0x616370-0x616f24).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D6308;

extern "C" void *exception__tf(void) {
    if (D_006D6308 == 0) {
        func_005BFB88(&D_006D6308, ((char *)"9exception"));
    }
    return &D_006D6308;
}
