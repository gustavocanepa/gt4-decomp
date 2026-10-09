typedef int s32;

extern void *mStorage__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void *mStorage__structor_1(void *arg0, s32 arg1) {
    void *r0 = hObject__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mStorage__vtable;
    *(void **)((char *)arg0 + 0x10) = (void *)(arg1);
    return r0;
}
