typedef int s32;

extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_00324798(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00674698;

extern "C" void func_003017A0(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00674698;
    func_00309378((char *)arg0 + 0x14, 2);
    func_00324798(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
