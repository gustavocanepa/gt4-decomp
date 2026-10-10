/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): an out-of-line (linkonce) copy of a member of the C++ runtime's classes (type_info and its __*_type_info subclasses, exception, bad_alloc, bad_cast, bad_typeid, bad_exception: cp/tinfo.h, typeinfo, exception, new), from the block the runtime's objects brought (0x616370-0x616f24).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef unsigned int u32;

extern "C" void __user_type_info__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_008A20A0;

extern int D_008A20C0;

extern "C" void *__class_type_info__tf(void) {
    if (D_008A20C0 == 0) {
        __user_type_info__tf();
        func_005BFB68(&D_008A20C0, ((char *)"17__class_type_info"), &D_008A20A0);
    }
    return &D_008A20C0;
}
