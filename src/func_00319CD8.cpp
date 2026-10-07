typedef int s32;

extern "C" void func_00323B60(void *arg0, s32 arg1);
extern "C" void func_00319538(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00676168;

extern "C" void func_00319CD8(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00676168;
    func_00323B60((char *)arg0 + 0xC, 2);
    func_00319538(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
