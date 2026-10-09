typedef int s32;

extern void *mScrollBox__vtable;
extern "C" void *mComposite__structor_0(void *);

extern "C" void *mScrollBox__structor_0(void *arg0) {
    void *r0 = mComposite__structor_0(arg0);
    *(void **)((char *)arg0 + 0xb0) = 0x0;
    *(void **)((char *)arg0 + 0x4) = &mScrollBox__vtable;
    *(void **)((char *)arg0 + 0xb4) = 0x0;
    *(void **)((char *)arg0 + 0xb8) = 0x0;
    *(void **)((char *)arg0 + 0xbc) = 0x0;
    return r0;
}
