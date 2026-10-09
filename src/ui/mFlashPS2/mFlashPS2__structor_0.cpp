typedef int s32;

extern void *mFlashPS2__vtable;
extern "C" void *mFlash__structor_0(void *);

extern "C" void *mFlashPS2__structor_0(void *arg0) {
    void *r0 = mFlash__structor_0(arg0);
    *(void **)((char *)arg0 + 0xc) = 0x0;
    *(void **)((char *)arg0 + 0x4) = &mFlashPS2__vtable;
    *(void **)((char *)arg0 + 0x10) = 0x0;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    return r0;
}
