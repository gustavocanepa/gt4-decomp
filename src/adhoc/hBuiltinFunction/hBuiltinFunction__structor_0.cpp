typedef int s32;

extern void *hBuiltinFunction__vtable;
extern "C" void *hFunctionValue__structor_0(void *);

extern "C" void *hBuiltinFunction__structor_0(void *arg0, s32 arg1, s32 arg2) {
    void *r0 = hFunctionValue__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &hBuiltinFunction__vtable;
    *(void **)((char *)arg0 + 0xc) = (void *)(arg2);
    return r0;
}
