typedef int s32;

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_0030F808(void *arg0, s32 arg1);

extern void *hInst__vtable;
extern void *mImport__vtable;

extern "C" void hInst__structor_10(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mImport__vtable;
    func_0030F808((char *)arg0 + 8, 2);
    *(void **)((char *)arg0 + 4) = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x1C, 4, "RefCounter");
    }
}
