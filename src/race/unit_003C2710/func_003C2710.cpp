typedef int s32;

extern void *D_006863A0;
extern "C" void *func_003C26A8(void *);

extern "C" void *func_003C2710(void *arg0) {
    void *r0 = func_003C26A8(arg0);
    if (r0 != 0) {
        *(void **)((char *)r0 + 0x4) = &D_006863A0;
        *(void **)(r0) = *(void **)((char *)arg0 + 0x4);
        *(void **)((char *)arg0 + 0x4) = r0;
    }
    return r0;
}
