typedef int s32;

extern "C" void func_00485C50(void *arg0, s32 arg1);
extern "C" void mComposite__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mProject__vtable;

extern "C" void mProject__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mProject__vtable;
    func_00485C50((char *)arg0 + 0xB0, 2);
    mComposite__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xB8, 4, "RefCounter");
    }
}
