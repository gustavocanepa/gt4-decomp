typedef int s32;

extern void *mAnchorActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mAnchorActor__structor_0(void *arg0) {
    void *r0 = mActor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mAnchorActor__vtable;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x20) = (void *)(0x1);
    *(void **)((char *)arg0 + 0x24) = (void *)(0x1);
    return r0;
}
