typedef int s32;

extern void *mComposite__vtable;
extern "C" void *mWidget__structor_0(void *);

extern "C" void *mComposite__structor_0(void *arg0) {
    void *r0 = mWidget__structor_0(arg0);
    *(void **)((char *)arg0 + 0xa0) = 0x0;
    *(void **)((char *)arg0 + 0x4) = &mComposite__vtable;
    *(void **)((char *)arg0 + 0xa4) = 0x0;
    *(void **)((char *)arg0 + 0xa8) = 0x0;
    *(void **)((char *)arg0 + 0xac) = 0x0;
    return r0;
}
