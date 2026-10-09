typedef int s32;

extern "C" void func_002F4210(void *arg0, s32 arg1);
extern "C" void hMethodValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hScriptMethod__vtable;

extern "C" void hScriptMethod__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &hScriptMethod__vtable;
    func_002F4210((char *)arg0 + 0xC, 2);
    hMethodValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
