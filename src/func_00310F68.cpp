typedef int s32;

extern "C" void func_002F4210(void *arg0, s32 arg1);
extern "C" void func_00303980(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00675158;

extern "C" void func_00310F68(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00675158;
    func_002F4210((char *)arg0 + 0xC, 2);
    func_00303980(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
