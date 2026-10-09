typedef int s32;

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *hMethodValue__structor_0(void *arg0);
extern char hScriptMethod__vtable[];

extern "C" s32 hScriptMethod__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hMethodValue__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = hScriptMethod__vtable;
    return func_002F41F8((char *)arg0 + 0xC, arg2);
}
