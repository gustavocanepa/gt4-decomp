typedef int s32;

extern "C" void func_0028BCA8(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00663900;

extern "C" void func_00210798(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00663900;
    func_0028BCA8(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 8, 4, "RefCounter");
    }
}
