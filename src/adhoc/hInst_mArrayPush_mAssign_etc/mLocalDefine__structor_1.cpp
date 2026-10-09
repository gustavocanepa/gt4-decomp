typedef int s32;

extern "C" void hInst__structor_0(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mLocalDefine__vtable;

extern "C" void mLocalDefine__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mLocalDefine__vtable;
    hInst__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC, 4, "RefCounter");
    }
}
