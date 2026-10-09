typedef int s32;

extern "C" void hFunctionValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hBuiltinFunction__vtable;

extern "C" void hBuiltinFunction__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &hBuiltinFunction__vtable;
    hFunctionValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
