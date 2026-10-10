/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): an out-of-line (linkonce) copy of a member of the C++ runtime's classes (type_info and its __*_type_info subclasses, exception, bad_alloc, bad_cast, bad_typeid, bad_exception: cp/tinfo.h, typeinfo, exception, new), from the block the runtime's objects brought (0x616370-0x616f24).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;

struct Obj {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char __class_type_info__vtable[];

extern "C" void func_00616830(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unkC = arg3;
    arg0->unk0 = arg1;
    arg0->unk8 = arg2;
    arg0->unk4 = __class_type_info__vtable;
}
