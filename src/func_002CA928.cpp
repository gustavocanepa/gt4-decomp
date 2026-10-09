typedef int s32;

extern "C" void func_00228480(void *arg0, s32 arg1);
extern "C" void func_002A1028(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_0066F938;

extern "C" void func_002CA928(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_0066F938;
    func_00228480((char *)arg0 + 0xF0, 2);
    func_002A1028(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x100, 4, "RefCounter");
    }
}
