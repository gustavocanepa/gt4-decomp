typedef int s32;

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void *func_0031E6D8(s32 arg0);

extern void *hInst__vtable;
extern void *mPop__vtable;

extern "C" void hInst__structor_21(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mPop__vtable;
    func_0031E6D8(0);
    *(void **)((char *)arg0 + 4) = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 8, 4, "RefCounter");
    }
}
