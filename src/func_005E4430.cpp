typedef int s32;

extern "C" void func_0026BB70(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00669418;

extern "C" void func_005E4430(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00669418;
    func_0026BB70(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x30, 4, "RefCounter");
    }
}
