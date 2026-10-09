typedef int s32;

extern void *mHBox__vtable;
extern "C" void *mDBox__structor_0(void *, s32);

extern "C" void *mHBox__structor_0(void *arg0) {
    void *r0 = mDBox__structor_0(arg0, 0x1);
    *(void **)((char *)arg0 + 0x4) = &mHBox__vtable;
    return r0;
}
