typedef int s32;

extern void *mMagnifyActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mMagnifyActor__structor_0(void *arg0) {
    void *r0 = mActor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mMagnifyActor__vtable;
    *(float *)((char *)arg0 + 0x18) = 1.0000000298f;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x2c) = 0x0;
    *(void **)((char *)arg0 + 0x30) = 0x0;
    *(float *)((char *)arg0 + 0x34) = 0.0166666661389f;
    return r0;
}
