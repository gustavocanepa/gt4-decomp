typedef int s32;

extern void *hInt__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void *hInt__structor_0(void *arg0, s32 arg1) {
    void *r0 = hObject__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &hInt__vtable;
    *(void **)((char *)arg0 + 0x10) = (void *)(arg1);
    return r0;
}
