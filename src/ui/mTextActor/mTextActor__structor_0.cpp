typedef int s32;

extern void *mTextActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mTextActor__structor_0(void *arg0) {
    void *r0 = mActor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x4) = &mTextActor__vtable;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    return r0;
}
