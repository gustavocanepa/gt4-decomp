typedef int s32;

extern void *mTransition__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void *mTransition__structor_0(void *arg0) {
    void *r0 = hObject__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mTransition__vtable;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x10) = 0x0;
    *(void **)((char *)arg0 + 0x14) = (void *)(0x3);
    *(void **)((char *)arg0 + 0x18) = (void *)(0x3);
    return r0;
}
