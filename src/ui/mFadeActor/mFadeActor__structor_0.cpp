typedef int s32;

extern void *mFadeActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mFadeActor__structor_0(void *arg0) {
    void *r0 = mActor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mFadeActor__vtable;
    *(float *)((char *)arg0 + 0x24) = 0.0333333322778f;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x28) = 0x0;
    *(void **)((char *)arg0 + 0x2c) = 0x0;
    *(void **)((char *)arg0 + 0x30) = 0x0;
    *(void **)((char *)arg0 + 0x34) = 0x0;
    *(void **)((char *)arg0 + 0x38) = 0x0;
    *(void **)((char *)arg0 + 0x3c) = 0x0;
    return r0;
}
