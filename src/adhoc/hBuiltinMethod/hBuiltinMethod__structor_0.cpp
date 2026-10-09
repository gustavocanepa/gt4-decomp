typedef int s32;

extern void *hBuiltinMethod__vtable;
extern "C" void *hMethodValue__structor_0(void *);

extern "C" void *hBuiltinMethod__structor_0(void *arg0, s32 arg1, s32 arg2) {
    void *r0 = hMethodValue__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &hBuiltinMethod__vtable;
    *(void **)((char *)arg0 + 0xc) = (void *)(arg2);
    return r0;
}
