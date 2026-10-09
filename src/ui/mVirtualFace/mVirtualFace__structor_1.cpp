typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_00309378(void *, s32);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mWidget__structor_1(void *, s32);

extern void *mVirtualFace__vtable;

extern "C" void mVirtualFace__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mVirtualFace__vtable;
    func_00309378((char *)arg0 + 0xA4, 2);
    func_002F9B38((char *)arg0 + 0xA0, 2);
    mWidget__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xA8, 4, "RefCounter");
    }
}
