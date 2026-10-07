typedef int s32;

extern "C" void func_00323C58(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00676BC8;

extern "C" void func_0032E680(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00676BC8;
    func_00323C58(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
