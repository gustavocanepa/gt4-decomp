/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): an out-of-line (linkonce) copy of a member of the C++ runtime's classes (type_info and its __*_type_info subclasses, exception, bad_alloc, bad_cast, bad_typeid, bad_exception: cp/tinfo.h, typeinfo, exception, new), from the block the runtime's objects brought (0x616370-0x616f24).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
extern "C" void type_info__virtual_00(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *__user_type_info__vtable;

extern "C" void __class_type_info__virtual_00(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &__user_type_info__vtable;
    type_info__virtual_00(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
