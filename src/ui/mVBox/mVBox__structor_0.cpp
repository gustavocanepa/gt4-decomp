typedef int s32;

extern void *mVBox__vtable;
extern "C" void *mDBox__structor_0(void *, s32);

extern "C" void *mVBox__structor_0(void *arg0) {
    void *r0 = mDBox__structor_0(arg0, 0x0);
    *(void **)((char *)arg0 + 0x4) = &mVBox__vtable;
    return r0;
}
